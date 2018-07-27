#ifndef ABSTRACTDATABASEFORMATTER_H
#define ABSTRACTDATABASEFORMATTER_H

#include <QString>
#include <QVariant>

class AbstractDatabaseFormatter
{
public:
    AbstractDatabaseFormatter();

    virtual QString getFormattedFieldName(const QString &fieldname) = 0;
    virtual QString getFormattedValue(const QVariant &value) = 0;
};

#endif // ABSTRACTDATABASEFORMATTER_H
