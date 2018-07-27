#ifndef POSTGRESQLPROVIDER_H
#define POSTGRESQLPROVIDER_H

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

    std::shared_ptr<AbstractDatabaseQuery> exec(const char *sql) const override;

private:
    void *_connection;
};

#endif // POSTGRESQLPROVIDER_H
