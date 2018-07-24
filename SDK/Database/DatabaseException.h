#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <Exceptions/BaseException.h>
#include <Database/AbstractDatabaseProvider.h>

class SDKSHARED_EXPORT DatabaseException : public BaseException
{
public:
    DatabaseException(const AbstractDatabaseProvider *provider, QString message);

    const AbstractDatabaseProvider *getDatabaseProvider() { return _provider; }

private:
    const AbstractDatabaseProvider *_provider;
};

#endif // DATABASEEXCEPTION_H
