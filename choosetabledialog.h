#ifndef CHOOSETABLEDIALOG_H
#define CHOOSETABLEDIALOG_H

#include <QDialog>

namespace Ui {
class chooseTableDialog;
}

class chooseTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chooseTableDialog(QWidget *parent = nullptr);
    ~chooseTableDialog();

private:
    Ui::chooseTableDialog *ui;
};

#endif // CHOOSETABLEDIALOG_H
