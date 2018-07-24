#include "DatabaseConnectionRefusedException.h"

DatabaseConnectionRefusedException::DatabaseConnectionRefusedException(
        const AbstractConnectionStringProvider &connectionString,
        const AbstractDatabaseProvider *provider,
        QString message) :
    DatabaseException(provider, message),
    _connectionString(connectionString)
{

}
