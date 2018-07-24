#ifndef DATABASECONNECTIONREFUSEDEXCEPTION_H
#define DATABASECONNECTIONREFUSEDEXCEPTION_H

#include "DatabaseException.h"
#include "AbstractConnectionStringProvider.h"
#include <SDK/sdk_global.h>

class SDKSHARED_EXPORT DatabaseConnectionRefusedException : public DatabaseException
{
public:
    DatabaseConnectionRefusedException(const AbstractConnectionStringProvider &connectionString,
                                       const AbstractDatabaseProvider *provider,
                                       QString message);

    const AbstractConnectionStringProvider &getConnectionString() { return _connectionString; }

private:
    const AbstractConnectionStringProvider &_connectionString;
};

#endif // DATABASECONNECTIONREFUSEDEXCEPTION_H
