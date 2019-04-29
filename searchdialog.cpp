#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
//    qDebug() << parent->objectName();
}

SearchDialog::SearchDialog(QWidget *parent, QStringList tableList) :
    QDialog(parent)
{
    ui->setupUi(this);
//    qDebug() << tableList;
//    ui->tableComboBox->addItems(*tableList);
//    foreach(QString tableName, tableList)
//    {
//        ui->tableComboBox->addItem(tableName);
//    }
}

//SearchDialog::SearchDialog(QWidget *parent, QSqlTableModel * const model) :
//    QDialog (parent),
//    model(model)
//{
//    ui->setupUi(this);
//}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_buttonBox_accepted()
{
    id = ui->idLineEdit->text();
    name = ui->nameLineEdit->text();
    department = ui->departmentLineEdit->text();
    status = ui->statusLineEdit->text();
    QString filter = "";
    if(!id.isEmpty())
    {
        filter += " id=" + id;
    }
    if(!name.isEmpty())
    {
        filter += " username='" + name + "'";
    }
    if(!department.isEmpty())
    {
        filter += " department='" + department + "'";
    }
    if(!status.isEmpty())
    {
        filter += " status=" + status;
    }
    //set parent's filter
    MainWindow *parentptr = (MainWindow*)parent();
    parentptr->setModelFilter(filter);
}

void SearchDialog::on_searchButton_clicked()
{
    ui->lineEditFrame->setEnabled(true);
}
