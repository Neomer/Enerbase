#ifndef POSTGRESQLQUERY_H
#define POSTGRESQLQUERY_H

#include <libpq-fe.h>

#include "postgresql_global.h"
#include <SDK/Database/AbstractDatabaseQuery.h>

class POSTGRESQLSHARED_EXPORT PostgreSQLQuery : public AbstractDatabaseQuery
{
public:
    PostgreSQLQuery(PGresult *result);

    // AbstractDatabaseQuery interface
public:
    virtual void close() override;
    virtual bool first() override;
    virtual bool last() override;
    virtual bool next() override;
    virtual bool prev() override;
    virtual void fields(QStringList &result) override;
    virtual int rowCount() override;
    virtual int fieldsCount() override;
    virtual QVariant value() override;

private:
    PGresult *_result;
};

#endif // POSTGRESQLQUERY_H
