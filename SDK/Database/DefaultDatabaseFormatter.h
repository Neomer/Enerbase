#ifndef DEFAULTDATABASEFORMATTER_H
#define DEFAULTDATABASEFORMATTER_H

#include "AbstractDatabaseFormatter.h"
#include <SDK/sdk_global.h>

class SDKSHARED_EXPORT DefaultDatabaseFormatter : public AbstractDatabaseFormatter
{
public:
    DefaultDatabaseFormatter();

    // AbstractDatabaseFormatter interface
public:
    virtual QString getFormattedFieldName(const QString &fieldname) const override;
    virtual QString getFormattedValue(const QVariant &value) const override;
    virtual QString getFormattedTableName(const QString &tablename) const override;
};

#endif // DEFAULTDATABASEFORMATTER_H
