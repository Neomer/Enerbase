#include "PostgreSQLProvider.h"
#include <SDK/Helpers/StringHelper.h>

#include "PostgreSQLQuery.h"

PostgreSQLProvider::PostgreSQLProvider() :
    _connection(nullptr)
{
}

void PostgreSQLProvider::open(const AbstractConnectionStringProvider &connectionString)
{
    _connection = PQconnectdb(StringHelper::StringToConstChar(connectionString.toString()));

    if (PQstatus(_connection) == CONNECTION_BAD)
    {
        throw DatabaseConnectionRefusedException(connectionString, this, QString("Connection failed!"));
    }
}

void PostgreSQLProvider::close()
{
    if (_connection == nullptr)
    {
        throw DatabaseException(this, "Trying to close already closed connection!");
    }

    PQfinish(_connection);
}

std::shared_ptr<AbstractDatabaseQuery> PostgreSQLProvider::exec(const QStringView &sql)
{
    if (_connection == nullptr)
    {
        throw DatabaseException(this, "Connection is closed!");
    }

    return std::shared_ptr<AbstractDatabaseQuery>(new PostgreSQLQuery(PQexec(_connection, StringHelper::StringToConstChar(query))));
}
