#include "mainwindow.h"
//#include "usertable.h"
//#include "departmenttable.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    UserTable w;
    MainWindow w;
    w.show();

    return a.exec();
}
