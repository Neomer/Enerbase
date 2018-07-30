#include <libpq-fe.h>
#include <QDebug>

#include <SDK/Helpers/StringHelper.h>
#include <SDK/Database/DefaultDatabaseFormatter.h>

#include "PostgreSQLProvider.h"
#include "PostgreSQLQuery.h"

#include <SDK/Helpers/StringHelper.h>

PostgreSQLProvider::PostgreSQLProvider() :
    _connection(nullptr),
    _formater(new DefaultDatabaseFormatter())
{
}

PostgreSQLProvider::~PostgreSQLProvider()
{
    delete _formater;
}

void PostgreSQLProvider::open(const AbstractConnectionStringProvider &connectionString)
{
    auto cstr = connectionString.toString();
    char *cs = new char[StringHelper::StringLength(cstr)];
    StringHelper::StringToConstChar(cstr, cs);
    _connection = PQconnectdb(cs);
    if (PQstatus((const PGconn *) _connection) == CONNECTION_BAD)
    {
        delete [] cs;
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

std::shared_ptr<AbstractDatabaseQuery> PostgreSQLProvider::exec(const char *sql) const
{
    if (_connection == nullptr)
    {
        throw DatabaseException(this, "Connection is closed!");
    }
    return std::shared_ptr<AbstractDatabaseQuery>(new PostgreSQLQuery(this, PQexec((PGconn*)_connection, sql)));
}

const AbstractDatabaseFormatter *PostgreSQLProvider::getFormatter() const
{
    return _formater;
}
