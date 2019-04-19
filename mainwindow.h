#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "usertable.h"
#include "departmenttable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_usernameEdit_returnPressed();

    void on_passwordEdit_returnPressed();

    void on_logoutButton_clicked();

    void on_viewUserButton_clicked();

    void on_viewDepartmentsButton_clicked();

    void on_editButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_submitButton_clicked();

    void on_revertButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery query;
    UserTable *userTable;
    DepartmentTable *departmentTable;
    QSqlTableModel *model;

private:
    void proceedToView();
    void logout();

};

#endif // MAINWINDOW_H
