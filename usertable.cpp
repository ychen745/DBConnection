#include "usertable.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>

UserTable::UserTable(QWidget *parent) : QWidget(parent)
{
//    this->db = database;
//    if(!db.open()){
//        qDebug() << "failed to open database";
//        exit(0);
//    }

//    model = new QSqlTableModel(nullptr, db);
    model = new QSqlTableModel;
//    qDebug() << db.hostName();
//    qDebug() << model->database();
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    view = new QTableView;
    view->setModel(model);
//    view->show();

    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addWidget(view);

    QHBoxLayout *hbox = new QHBoxLayout;
    lay->addLayout(hbox);

    QPushButton *submit = new QPushButton("submit");
    connect(submit, SIGNAL(clicked()), this, SLOT(slotSubmitClicked()));

    QPushButton *del = new QPushButton("delete");
    connect(del, SIGNAL(clicked()), this, SLOT(slotDelClicked()));

    QPushButton *add = new QPushButton("add");
    connect(add, SIGNAL(clicked()), this, SLOT(slotAddClicked()));

    QPushButton *close = new QPushButton("Close");
    connect(close, SIGNAL(clicked()), this, SLOT(slotCloseClicked()));

    hbox->addStretch();
    hbox->addWidget(add);
    hbox->addWidget(del);
    hbox->addWidget(submit);
    hbox->addWidget(close);
    hbox->addStretch();
}

void UserTable::slotAddClicked()
{
    QSqlRecord record = model->record();
    model->insertRecord(-1, record);
}

void UserTable::slotDelClicked()
{
    QItemSelectionModel *selectModel = view->selectionModel();
    QModelIndexList selectList = selectModel->selectedIndexes();
    QList<int> delRow;

    for(int i = 0; i < selectList.size(); i++){
        QModelIndex index = selectList.at(i);
//        model->removeRow(index.row());
        delRow << index.row();
    }
    while(delRow.size() > 0){
        int row = delRow.at(0);
        delRow.removeAll(row);
        model->removeRow(row);
    }
    if(QMessageBox::question(this, "Alert", "Are you sure?") == QMessageBox::Yes)
    {
        model->submitAll();
    }
}

void UserTable::slotSubmitClicked()
{
    if(QMessageBox::question(this, "Alert", "Are you sure?") == QMessageBox::Yes)
    {
        model->submitAll();
    }
}

void UserTable::slotCloseClicked()
{
    this->close();
}
