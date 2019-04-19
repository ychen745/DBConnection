#include "departmenttable.h"

#include <QVBoxLayout>
#include <QPushButton>

DepartmentTable::DepartmentTable(QWidget *parent) : QWidget(parent)
{
    _model = new QSqlTableModel;
    _model->setTable("department");
    _model->select();
    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    _view = new QTableView;
    _view->setModel(_model);

//    _view->setItemDelegateForColumn(0, new ReadOnlyDelegate);

    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addWidget(_view);

    QHBoxLayout *hbox = new QHBoxLayout;
    lay->addLayout(hbox);

    QPushButton *submit = new QPushButton("submit");
//    connect(submit, SIGNAL(clicked()), this, SLOT(slotSubmitClicked()));

    QPushButton *del = new QPushButton("delete");
//    connect(del, SIGNAL(clicked()), this, SLOT(slotDelClicked()));

    QPushButton *add = new QPushButton("add");
//    connect(add, SIGNAL(clicked()), this, SLOT(slotAddClicked()));

    hbox->addStretch();
    hbox->addWidget(add);
    hbox->addWidget(del);
    hbox->addWidget(submit);
    hbox->addStretch();
}
