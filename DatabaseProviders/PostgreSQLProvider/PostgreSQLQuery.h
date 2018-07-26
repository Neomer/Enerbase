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
    virtual void fields(QStringList &result) const override;
    virtual int rowCount() const override;
    virtual bool hasField(const char *name) const override;
    virtual i32 field(const char *name) const override;
    virtual int fieldsCount() const override;
    virtual QVariant value(int index) const override;
    virtual QVariant value(const char *name) const override;
    virtual bool isValid() const override;
    virtual bool isEmpty() const override;

private:
    PGresult *_result;
    const AbstractDatabaseProvider *_provider;

    void getFormattedValue(const char *c_value, Oid type_id, QVariant &value) const;
 };

#endif // POSTGRESQLQUERY_H
