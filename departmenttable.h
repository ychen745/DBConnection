#ifndef DEPARTMENTTABLE_H
#define DEPARTMENTTABLE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QItemDelegate>
#include "datatable.h"

class DepartmentTableDelegate : public QItemDelegate
{
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
    {
        return NULL;
    }
};

class DepartmentTableModel : public QSqlTableModel
{
public:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const
    {
        QSqlTableModel::data(idx, role);
        QVariant var = QSqlTableModel::data(idx, role);
        return var;
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
    {
        return false;
    }
};

class DepartmentTable : public QWidget
{
    Q_OBJECT
public:
    explicit DepartmentTable(QWidget *parent = nullptr);
    QSqlTableModel *model;
    QTableView *view;

signals:

public slots:
    void slotSubmitClicked();
    void slotDelClicked();
    void slotAddClicked();
    void slotCloseClicked();
};

#endif // DEPARTMENTTABLE_H
