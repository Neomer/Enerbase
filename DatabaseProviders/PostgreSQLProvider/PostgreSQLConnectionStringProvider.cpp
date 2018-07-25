#include <QDebug>

#include "PostgreSQLConnectionStringProvider.h"

PostgreSQLConnectionStringProvider::PostgreSQLConnectionStringProvider()
{

}

QString PostgreSQLConnectionStringProvider::toString() const
{
    QString ret("host=%1 port=%2 dbname=%3 user=%4 password=%5 connect_timeout=3");
    return ret.arg(getHost(), QString::number(getPort()), getDatabase(), getUsername(), getPassword());
 }
