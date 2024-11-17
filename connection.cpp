#include "connection.h"

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver load "<<db.isValid();
    QString dsn = QString::fromLocal8Bit("HSRDB");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("suzune");                               //登录用户
    db.setPassword("suzune0423zsw");                              //密码
    if(!db.open())                                      //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return false;                                   //打开失败
    }
    else
    {
        qDebug()<<"database open success!";
    }
    return true;
}
bool rmConnection()
{
    //QSqlDatabase db= QSqlDatabase::database("QODBC");
    //db.close();//关闭数据库
    QString name;
    {
        name = QSqlDatabase::database().connectionName();
    }
    QSqlDatabase::removeDatabase(name);
    return 0;

}
