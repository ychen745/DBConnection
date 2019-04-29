#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T09:00:15
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBConnection
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    choosetabledialog.cpp \
        main.cpp \
        mainwindow.cpp \
#    usertable.cpp \
#    departmenttable.cpp \
#    mysqlhandle.cpp \
    datatable.cpp \
    searchdialog.cpp

HEADERS += \
    choosetabledialog.h \
        mainwindow.h \
#    usertable.h \
#    departmenttable.h \
#    mysqlhandle.h \
    datatable.h \
    searchdialog.h

FORMS += \
        choosetabledialog.ui \
        mainwindow.ui \
        searchdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Connector C++ 8.0/lib64/vs14/' -lmysqlcppconn

INCLUDEPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C++ 8.0/include'
DEPENDPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C++ 8.0/include'

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C++ 8.0/lib64/vs14/mysqlcppconn.lib'
#else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C++ 8.0/lib64/vs14/libmysqlcppconn.a'

unix|win32: LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/include'
DEPENDPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/include'

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/libmysql.lib'
#else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/liblibmysql.a'
