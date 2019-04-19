#include "departmenttable.h"

#include <QVBoxLayout>
#include <QPushButton>

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>

DepartmentTable::DepartmentTable(QWidget *parent) : QWidget(parent)
{
    model = new QSqlTableModel;
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    view = new QTableView;
    view->setModel(model);

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

void DepartmentTable::slotAddClicked()
{
    QSqlRecord record = model->record();
    model->insertRecord(-1, record);
}

void DepartmentTable::slotDelClicked()
{
    QItemSelectionModel *selectModel = view->selectionModel();
    QModelIndexList selectList = selectModel->selectedIndexes();
    QList<int> delRow;

    for(int i = 0; i < selectList.size(); i++){
        QModelIndex index = selectList.at(i);
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

void DepartmentTable::slotSubmitClicked()
{
    if(QMessageBox::question(this, "Alert", "Are you sure?") == QMessageBox::Yes)
    {
        model->submitAll();
    }
}

void DepartmentTable::slotCloseClicked()
{
    this->close();
}

