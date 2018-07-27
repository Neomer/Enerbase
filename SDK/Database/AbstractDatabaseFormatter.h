#ifndef ABSTRACTDATABASEFORMATTER_H
#define ABSTRACTDATABASEFORMATTER_H

#include <QString>
#include <QVariant>

class AbstractDatabaseFormatter
{
public:
    AbstractDatabaseFormatter();
    virtual ~AbstractDatabaseFormatter();

    virtual QString getFormattedTableName(const QString &tablename) const = 0;
    virtual QString getFormattedFieldName(const QString &fieldname) const = 0;
    virtual QString getFormattedValue(const QVariant &value) const = 0;
};

#endif // ABSTRACTDATABASEFORMATTER_H
