#ifndef ABSTRACTDATABASEQUERY_H
#define ABSTRACTDATABASEQUERY_H

#include <QStringList>
#include <QVariant>

#include <BasicTypes.h>
#include "../sdk_global.h"

class SDKSHARED_EXPORT AbstractDatabaseQuery
{
public:
    AbstractDatabaseQuery();
    virtual ~AbstractDatabaseQuery();

    virtual void close() = 0;

    virtual bool first() = 0;
    virtual bool last() = 0;
    virtual bool next() = 0;
    virtual bool prev() = 0;

    virtual bool isEnd() const = 0;

    virtual i32 field(const char *name) const = 0;
    virtual void fields(QStringList &result) const = 0;

    virtual int rowCount() const = 0;
    virtual int fieldsCount() const = 0;

    virtual QVariant value(int index) const = 0;
    virtual QVariant value(const char *name) const = 0;
    virtual QVariant value(QString name) const;

    virtual bool isValid() const = 0;
    virtual bool isEmpty() const { return rowCount() == 0; }
};

#endif // ABSTRACTDATABASEQUERY_H
