#ifndef DEFAULTDATABASEFORMATTER_H
#define DEFAULTDATABASEFORMATTER_H

#include "AbstractDatabaseFormatter.h"

class DefaultDatabaseFormatter : public AbstractDatabaseFormatter
{
public:
    DefaultDatabaseFormatter();

    // AbstractDatabaseFormatter interface
public:
    virtual QString getFormattedFieldName(const QString &fieldname) override;
    virtual QString getFormattedValue(const QVariant &value) override;
};

#endif // DEFAULTDATABASEFORMATTER_H
