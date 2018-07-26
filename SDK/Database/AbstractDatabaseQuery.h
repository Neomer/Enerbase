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

    virtual bool isEnd() = 0;

    virtual i32 field(const char *name) = 0;
    virtual void fields(QStringList &result) = 0;

    virtual int rowCount() = 0;
    virtual int fieldsCount() = 0;

    virtual QVariant value(int index) = 0;
    virtual QVariant value(const char *name) = 0;
    virtual QVariant value(QString name);

    virtual bool isValid() = 0;
    virtual bool isEmpty() { return rowCount() == 0; }
};

#endif // ABSTRACTDATABASEQUERY_H
