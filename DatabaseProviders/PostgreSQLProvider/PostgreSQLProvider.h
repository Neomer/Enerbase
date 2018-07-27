#ifndef POSTGRESQLPROVIDER_H
#define POSTGRESQLPROVIDER_H

#include <memory>

#include "postgresql_global.h"
#include <SDK/Database/AbstractDatabaseProvider.h>
#include <SDK/Database/DatabaseConnectionRefusedException.h>

class POSTGRESQLSHARED_EXPORT PostgreSQLProvider : public AbstractDatabaseProvider
{
public:
    PostgreSQLProvider();
    ~PostgreSQLProvider();

    // AbstractDatabaseProvider interface
public:
    void open(const AbstractConnectionStringProvider &connectionString) override;
    void close() override;

    std::shared_ptr<AbstractDatabaseQuery> exec(const char *sql) const override;

private:
    void *_connection;
    AbstractDatabaseFormatter *_formater;

    // AbstractDatabaseProvider interface
public:
    virtual const AbstractDatabaseFormatter *getFormatter() const override;
};

#endif // POSTGRESQLPROVIDER_H
