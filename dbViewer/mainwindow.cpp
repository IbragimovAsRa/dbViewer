#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    connector();

    model = new QSqlTableModel(this, db);
    model->setTable("Users");
    model->select();

    proxyModel = new ProxyModel();
    proxyModel->setSourceModel(model);

    view = new QTableView();
    view->setModel(proxyModel );
    view->show();
}

MainWindow::~MainWindow()
{
    delete model;
    delete view;
}


bool MainWindow::connector() {
    bool isConnection = false;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./test.db");
    if (db.open()) {
        isConnection = true;
        qDebug() << "SUCCES";
    } else {
        qDebug() << "FAIL";
    }
    return isConnection;
}
