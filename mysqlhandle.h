#ifndef MYSQLHANDLE_H
#define MYSQLHANDLE_H

#define MAX_NAME_LEN 1024

#include <QString>
#include <QObject>
#include <QSqlDatabase>

struct STRU_SYS_FIELD;
struct st_mysql;
class MySqlHandle
{
public:
    MySqlHandle();
    MySqlHandle( int ii_LangType );
    ~MySqlHandle();

    enum {
        RES_OK = 0,
        RES_ERR = -1
    };

    //connect database
    int     InitHandle( const char *ipc_Host,
                        const char *ipc_User,
                        const char *ipc_Psw,
                        const char *ipc_Name,
                        int ii_Port );

    //free connection
    void    FreeHandle();

    //test DBA
    int     TestConnect( const char *ipc_Host,
                         const char *ipc_User,
                         const char *ipc_Psw,
                         int ii_Port = 0 );

    //check if database exists
    int     IsDBExist( const char *ipc_Host,
                       const char *ipc_User,
                       const char *ipc_Psw,
                       const char *ipc_Name,
                       int ii_Port = 0 );

    //create database
    int     CreateDB( const char *ipc_Host,
                      const char *ipc_User,
                      const char *ipc_Psw,
                      const char *ipc_Name,
                      int ii_Port = 0 );

    //check if the table exists
    int     IsTableExist( const QString &istr_Table );

    //create table
    int     CreateTable( const QString &istr_TableName, STRU_SYS_FIELD *ip_Field, int ii_FieldNum );

    //sql query
    int     SqlSelect( const QString &istr_Sql, QByteArray &o_BA, int &oi_Num, int ii_Flag );

    //non-query modifications
    int     SqlModify( const QString &istr_Sql );

    //事务处理
    int     SqlTransact( const QStringList &list_Sql );

    //get last error
    QString &GetLastErr(){
        if ( mstr_Error.length() == 0 )
        {
            mstr_Error = QObject::tr( "No error info.");
            mstr_Error = "";
        }
        return mstr_Error;
    }

    //是否连接状态
    bool    IsConnected(){ return mb_IsConnect; }

    //获得所有表名
    QStringList GetTableName();

    //PingDB
    void    PingDB();

private:
    //attributes
    QSqlDatabase db;
//    int mp_MySQL = 1;
    st_mysql    *mp_MySQL;
    int         mi_LangType;
    QString     mstr_Error;
    bool        mb_IsConnect;
    char        mpc_Host[MAX_NAME_LEN];
    char        mpc_User[MAX_NAME_LEN];
    char        mpc_Psw[MAX_NAME_LEN];
    char        mpc_Name[MAX_NAME_LEN];
    int         mi_Port;
    int         mi_ConnectTime;
    enum { MAX_CONNECT_TIME = 3600 };
};

#endif // MYSQLHANDLE_H
