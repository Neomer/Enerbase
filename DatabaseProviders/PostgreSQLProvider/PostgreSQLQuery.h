#ifndef POSTGRESQLQUERY_H
#define POSTGRESQLQUERY_H

#include <libpq-fe.h>

#include "postgresql_global.h"
#include <SDK/Database/BaseDatabaseQuery.h>
#include <SDK/Database/DatabaseQueryBaseException.h>
#include <SDK/Database/AbstractDatabaseProvider.h>

class POSTGRESQLSHARED_EXPORT PostgreSQLQuery : public BaseDatabaseQuery
{
public:
    PostgreSQLQuery(const AbstractDatabaseProvider *provider, PGresult *result);

    // AbstractDatabaseQuery interface
public:
    virtual void close() override;
    virtual void fields(QStringList &result) override;
    virtual int rowCount() override;
    virtual i32 field(const char *name) override;
    virtual int fieldsCount() override;
    virtual QVariant value(int index) override;
    virtual QVariant value(const char *name) override;
    virtual bool isValid() override;
    virtual bool isEmpty() override;

private:
    PGresult *_result;
    const AbstractDatabaseProvider *_provider;

    void getFormattedValue(const char *c_value, Oid type_id, QVariant &value);
 };

#endif // POSTGRESQLQUERY_H
