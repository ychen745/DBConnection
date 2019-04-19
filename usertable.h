#ifndef USERTABLE_H
#define USERTABLE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QItemDelegate>
#include "datatable.h"

class ReadOnlyDelegate : public QItemDelegate
{
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
    {
        return NULL;
    }
};

class UserTableModel : public QSqlTableModel
{
public:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const
    {
        QSqlTableModel::data(idx, role);
        QVariant var = QSqlTableModel::data(idx, role);
        return var;
    }
    bool setData(const QModelIndex &index, const QVariant value, int role = Qt::EditRole)
    {
        return false;
    }
};

class UserTable : public QWidget
{
    Q_OBJECT
public:
    explicit UserTable(QWidget *parent = nullptr);
//    UserTable(QWidget *parent = nullptr, const QSqlDatabase &database = QSqlDatabase::addDatabase("QMYSQL"));
    QSqlTableModel *model;
    QTableView *view;
//    QSqlDatabase db;

signals:

public slots:
    void slotSubmitClicked();
    void slotDelClicked();
    void slotAddClicked();
    void slotCloseClicked();
};

#endif // USERTABLE_H
