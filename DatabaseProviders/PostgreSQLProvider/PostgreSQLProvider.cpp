#include <libpq-fe.h>
#include <QDebug>

#include "PostgreSQLProvider.h"
#include <SDK/Helpers/StringHelper.h>

#include "PostgreSQLQuery.h"

PostgreSQLProvider::PostgreSQLProvider() :
    _connection(nullptr)
{
}

void PostgreSQLProvider::open(const AbstractConnectionStringProvider &connectionString)
{
    auto cstr = connectionString.toString();
    char cs[cstr.length()];
    StringHelper::StringToConstChar(cstr, cs);
    _connection = PQconnectdb(cs);
    if (PQstatus((const PGconn *) _connection) == CONNECTION_BAD)
    {
        throw DatabaseConnectionRefusedException(connectionString, this, PQerrorMessage((const PGconn *) _connection));
    }
}

void PostgreSQLProvider::close()
{
    if (_connection == nullptr)
    {
        throw DatabaseException(this, "Trying to close already closed connection!");
    }

    PQfinish((PGconn *)_connection);
}

std::shared_ptr<AbstractDatabaseQuery> PostgreSQLProvider::exec(const char *sql)
{
    if (_connection == nullptr)
    {
        throw DatabaseException(this, "Connection is closed!");
    }
    return std::shared_ptr<AbstractDatabaseQuery>(new PostgreSQLQuery(this, PQexec((PGconn*)_connection, sql)));
}
