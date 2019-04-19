#include "mysqlhandle.h"
#include <QTcpSocket>
#include <QHostInfo>
#include <QHostAddress>
#include <QtSql>
#include <mysql.h>

MySqlHandle::MySqlHandle()
{
    mb_IsConnect = false;
    memset(mpc_Host, 0, MAX_NAME_LEN);
    memset(mpc_User, 0, MAX_NAME_LEN);
    memset(mpc_Psw, 0, MAX_NAME_LEN);
    memset(mpc_Name, 0, MAX_NAME_LEN);
    mi_Port = 0;
    mi_ConnectTime = 0;
}

MySqlHandle::MySqlHandle(int ii_LangType)
{
    mi_LangType = ii_LangType;
    mb_IsConnect = false;
    mysql_init(mp_MySQL);
    memset(mpc_Host, 0, MAX_NAME_LEN);
    memset(mpc_User, 0, MAX_NAME_LEN);
    memset(mpc_Psw, 0, MAX_NAME_LEN);
    memset(mpc_Name, 0, MAX_NAME_LEN);
    mi_Port = 0;
    mi_ConnectTime = 0;
}

MySqlHandle::~MySqlHandle()
{
    FreeHandle();
    delete mp_MySQL;
}

int MySqlHandle::InitHandle(const char *ipc_Host,
                            const char *ipc_User,
                            const char *ipc_Psw,
                            const char *ipc_Name,
                            int ii_Port)
{
    mstr_Error = QString("");
    if (!mp_MySQL)
    {
        mstr_Error = QObject::tr( "Database initialization failed!" );
        return RES_ERR;
    }

    if (mb_IsConnect)
        return RES_OK;

    if (ii_Port == 0)
        ii_Port = 3306;

    if(!mysql_real_connect(mp_MySQL, ipc_Host, ipc_User, ipc_Psw, ipc_Name, ii_Port, NULL, 0))
    {
        const char *lpc_Temp = mysql_error(mp_MySQL);
        if (lpc_Temp && lpc_Temp[0] != 0)
            mstr_Error = QString(lpc_Temp);
        return RES_ERR;
    }

    mysql_query(mp_MySQL, "set character_set_connection=utf8");
    mysql_query(mp_MySQL, "set character_set_results=utf8");
    mysql_query(mp_MySQL, "set character_set_client=utf8");

    mb_IsConnect = true;

    if (mi_ConnectTime == 0)
    {
        strcpy(mpc_Host, ipc_Host);
        strcpy(mpc_User, ipc_User);
        strcpy(mpc_Psw, ipc_Psw);
        strcpy(mpc_Name, ipc_Name);
        mi_Port = ii_Port;
    }
    mi_ConnectTime = QDateTime::currentDateTime().toTime_t();

    return RES_OK;
}

void MySqlHandle::FreeHandle()
{

}

int MySqlHandle::TestConnect(const char *ipc_Host,
                             const char *ipc_User,
                             const char *ipc_Psw,
                             int ii_Port)
{
    mstr_Error = QString("");
    if (!mp_MySQL)
    {
        mstr_Error = QObject::tr("The database is not connected correctly.");
        return RES_ERR;
    }
    if (!mysql_real_connect(mp_MySQL, ipc_Host, ipc_User, ipc_Psw, "mysql", ii_Port, NULL, 0))
    {
        mstr_Error = QObject::tr("The database is not connected correctly.");
        const char *lpc_Temp = mysql_error(mp_MySQL);
        if (lpc_Temp && lpc_Temp[0] != 0)
        {
            mstr_Error.append("[");
            mstr_Error.append(CODEC(lpc_Temp));
            mstr_Error.append("]");
        }
        return RES_ERR;
    }
    mysql_close(mp_MySQL);
    return RES_OK;
}

int MySqlHandle::IsDBExist(const char *ipc_Host,
                           const char *ipc_User,
                           const char *ipc_Psw,
                           const char *ipc_Name,
                           int ii_Port)
{
    if(!mysql_real_connect(mp_MySQL, ipc_Host, ipc_User, ipc_Psw, ipc_Name, ii_Port, NULL, 0))
    {
        const char *lpc_Temp = "Database Connection Error";
        mstr_Error = lpc_Temp;
        return RES_ERR;
    }

    return RES_OK;
}

int MySqlHandle::CreateDB(const char *ipc_Host,
                          const char *ipc_User,
                          const char *ipc_Psw,
                          const char *ipc_Name,
                          int ii_Port)
{
    mstr_Error = QString("");
    if(!mp_MySQL)
    {
        mstr_Error = QObject::tr("The database is not connected correctly");
        return RES_ERR;
    }

    if(!mysql_real_connect(mp_MySQL, ipc_Host, ipc_User, ipc_Psw, ipc_Name, ii_Port, NULL, 0))
    {
        mstr_Error = QObject::tr("The database is not connected correctly.");
        const char *lpc_Temp = "The database is not connected correctly.";
        if(lpc_Temp && lpc_Temp[0] != 0)
        {
            mstr_Error.append(QString(lpc_Temp));
        }
    }
}

int MySqlHandle::IsTableExist(const QString &istr_Table)
{

}

int MySqlHandle::CreateTable(const QString &istr_TableName,
                             STRU_SYS_FIELD *ip_Field,
                             int ii_FieldNum)
{

}

int MySqlHandle::SqlSelect(const QString &istr_Sql,
                           QByteArray &o_BA,
                           int &oi_Num,
                           int ii_Flag)
{

}

int MySqlHandle::SqlModify(const QString &istr_Sql)
{

}

int MySqlHandle::SqlTransact(const QStringList &list_Sql)
{

}

QStringList MySqlHandle::GetTableName()
{

}

void MySqlHandle::PingDB()
{

}

