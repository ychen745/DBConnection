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

void MainWindow::proceedToLogin(){
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
    proceedToLogin();
}

void MainWindow::on_viewUserButton_clicked()
{
    userTable = new UserTable;
    userTable->show();
}

void MainWindow::on_viewDepartmentsButton_clicked()
{
    departmentTable = new DepartmentTable;
    departmentTable->show();
}
