#ifndef POSTGRESQLPROVIDER_H
#define POSTGRESQLPROVIDER_H

#include <libpq-fe.h>
#include <memory>

#include "postgresql_global.h"
#include <Database/AbstractDatabaseProvider.h>
#include <Database/DatabaseConnectionRefusedException.h>

class POSTGRESQLSHARED_EXPORT PostgreSQLProvider : public AbstractDatabaseProvider
{
public:
    PostgreSQLProvider();

    // AbstractDatabaseProvider interface
public:
    void open(const AbstractConnectionStringProvider &connectionString) override;
    void close() override;

    std::shared_ptr<AbstractDatabaseQuery> exec(const QStringView &sql) override;

private:
    PGconn *_connection;
};

#endif // POSTGRESQLPROVIDER_H
