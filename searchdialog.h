#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    explicit SearchDialog(QWidget *parent, QStringList tableList);
//    explicit SearchDialog(QWidget *parent, QSqlTableModel * const model);
    ~SearchDialog();

private slots:
    void on_buttonBox_accepted();
    void on_searchButton_clicked();

private:
    Ui::SearchDialog *ui;
//    QString table = "user";
//    QStringList tableList;
    QSqlTableModel *model;

    QString id;
    QString name;
    QString department;
    QString status;
};

#endif // SEARCHDIALOG_H
