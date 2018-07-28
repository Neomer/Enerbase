#ifndef ABSTRACTDATABASEPROVIDER_H
#define ABSTRACTDATABASEPROVIDER_H

#include <QStringView>
#include <memory>

#include "../sdk_global.h"
#include "AbstractDatabaseQuery.h"
#include "AbstractConnectionStringProvider.h"
#include "AbstractDatabaseFormatter.h"

class SDKSHARED_EXPORT AbstractDatabaseProvider
{
public:
    AbstractDatabaseProvider();
    AbstractDatabaseProvider(const AbstractDatabaseProvider &other);
    AbstractDatabaseProvider &operator =(const AbstractDatabaseProvider& other);
    virtual ~AbstractDatabaseProvider();

    virtual void open(const AbstractConnectionStringProvider &connectionString) = 0;
    virtual void close() = 0;

    virtual std::shared_ptr<AbstractDatabaseQuery> exec(const QStringView &sql) const;
    virtual std::shared_ptr<AbstractDatabaseQuery> exec(const char *sql) const = 0;

    virtual const AbstractDatabaseFormatter *getFormatter() const = 0;
};

#endif // ABSTRACTDATABASEPROVIDER_H
