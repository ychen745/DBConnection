#include "choosetabledialog.h"
#include "ui_choosetabledialog.h"

chooseTableDialog::chooseTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseTableDialog)
{
    ui->setupUi(this);
}

chooseTableDialog::~chooseTableDialog()
{
    delete ui;
}
