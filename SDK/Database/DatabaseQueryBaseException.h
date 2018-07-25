#ifndef DATABASEQUERYBASEEXCEPTION_H
#define DATABASEQUERYBASEEXCEPTION_H

#include <Database/DatabaseException.h>

class SDKSHARED_EXPORT DatabaseQueryBaseException : public DatabaseException
{
public:
    DatabaseQueryBaseException(const AbstractDatabaseProvider *provider, QString message);
};

#endif // DATABASEQUERYBASEEXCEPTION_H
