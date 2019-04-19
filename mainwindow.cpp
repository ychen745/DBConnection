#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usertable.h"
#include "departmenttable.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QKeyEvent>
#include <QSqlDriver>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::proceedToView(){
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    QString username = ui->usernameEdit->text();
//    db.setUserName(username);
    db.setUserName("ychen745");
    QString password = ui->passwordEdit->text();
//    db.setPassword(password);
    db.setPassword("19920223");
    db.setDatabaseName("test");
    if(!db.open()){
        qDebug() << "login failed";
    }
    else{
        qDebug() << "login success";
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::logout(){
    db.close();
    db.setHostName("");
    db.setPort(-1);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_loginButton_clicked()
{
    proceedToView();
}

void MainWindow::on_usernameEdit_returnPressed()
{
    proceedToView();
}

void MainWindow::on_passwordEdit_returnPressed()
{
    proceedToView();
}

void MainWindow::on_logoutButton_clicked()
{
    logout();
}

void MainWindow::on_viewUserButton_clicked()
{
//    userTable = new UserTable;
//    userTable->show();
    model = new QSqlTableModel;
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    QTableView *dataTableView = ui->dataTableView;
    dataTableView->setModel(model);
}

void MainWindow::on_viewDepartmentsButton_clicked()
{
    departmentTable = new DepartmentTable;
    departmentTable->show();
}

void MainWindow::on_editButton_clicked()
{
    ui->addButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
//    ui->submitButton->setEnabled(true);
}

void MainWindow::on_addButton_clicked()
{
    QSqlRecord record = model->record();
    model->insertRecord(-1, record);
    ui->submitButton->setEnabled(true);
}

void MainWindow::on_deleteButton_clicked()
{
    QItemSelectionModel *selectModel = ui->dataTableView->selectionModel();
    QModelIndexList selectList = selectModel->selectedIndexes();
    QList<int> delRow;
    for(int i = 0; i < selectList.size(); i++)
    {
        QModelIndex index = selectList.at(i);
        delRow << index.row();
    }
    while(delRow.size() > 0)
    {
        int row = delRow.at(0);
        delRow.removeAt(row);
        model->removeRow(row);
    }

    if(QMessageBox::question(this, "Alert", "Are you sure?") == QMessageBox::Yes)
    {
        model->submitAll();
    }
    ui->submitButton->setEnabled(true);
}

void MainWindow::on_submitButton_clicked()
{
    if(QMessageBox::question(this, "Alert", "Are you sure?") == QMessageBox::Yes)
    {
        model->submitAll();
    }
    ui->submitButton->setEnabled(false);
}

void MainWindow::on_revertButton_clicked()
{

}
