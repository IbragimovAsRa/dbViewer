#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDebug>

class ProxyModel : public QSortFilterProxyModel {
   Q_OBJECT
public:
    int	rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return QSortFilterProxyModel::columnCount(parent);
    }

    int	columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return QSortFilterProxyModel::rowCount(parent);
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)  const override{
        return sourceModel()->headerData(section,Qt::Orientation(orientation^3), role);
    }

    QModelIndex	index(int row, int column, const QModelIndex &parent = QModelIndex()) const override {
        return QSortFilterProxyModel::index(column, row, parent);
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    bool connector();

    QSqlDatabase db;
    QSqlTableModel* model;
    ProxyModel* proxyModel;
    QTableView* view;

};
#endif // MAINWINDOW_H
