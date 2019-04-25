#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractItemModel>
#include "usertable.h"
#include "departmenttable.h"

namespace Ui {
class MainWindow;
}

class FTDBModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FTDBModel(const int nCol, const int colCheckBox = 0, QObject *parent = nullptr);


//    Returns the number of rows under the given parent. When the parent is valid it means that rowCount is returning the number of children of parent.
//    Note: When implementing a table based model, rowCount() should return 0 when the parent is valid.
//    Note: This function can be invoked via the meta-object system and from QML.
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

//    Returns the number of columns for the children of the given parent.
//    In most subclasses, the number of columns is independent of the parent.
//    For example:

//      int DomModel::columnCount(const QModelIndex &/*parent*/) const
//      {
//          return 3;
//      }

//    Note: When implementing a table based model, columnCount() should return 0 when the parent is valid.
//    Note: This function can be invoked via the meta-object system and from QML.
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

//    Returns the data stored under the given role for the item referred to by the index.
//    Note: If you do not have a value to return, return an invalid QVariant instead of returning 0.
//    Note: This function can be invoked via the meta-object system and from QML.
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    //needed by editable models

//    Sets the role data for the item at index to value.
//    Returns true if successful; otherwise returns false.
//    The dataChanged() signal should be emitted if the data was successfully set.
//    The base class implementation returns false. This function and data() must be reimplemented for editable models.
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

//    Returns the item flags for the given index.
//    The base class implementation returns a combination of flags that enables the item (ItemIsEnabled) and allows it to be selected (ItemIsSelectable).
    Qt::ItemFlags flags(const QModelIndex &index) const;

};

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
    void initUi();
    void enableEdit();
};

#endif // MAINWINDOW_H
