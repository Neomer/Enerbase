#include <QDateTime>

#include "DefaultDatabaseFormatter.h"

DefaultDatabaseFormatter::DefaultDatabaseFormatter()
{

}

QString DefaultDatabaseFormatter::getFormattedFieldName(const QString &fieldname)const
{
    return QString("\"") + fieldname + "\"";
}

QString DefaultDatabaseFormatter::getFormattedValue(const QVariant &value)const
{
    switch (value.type())
    {
        case QVariant::Int:
        case QVariant::LongLong:
        case QVariant::UInt:
        case QVariant::ULongLong:
            return value.toString();

        case QVariant::DateTime:
            return value.toDateTime().toString("\"\"yyyy-MM-dd hh:mm:ss\"\"").replace("\"\"", "'");

        case QVariant::Date:
            return value.toDate().toString("\'yyyy-MM-dd\'");

        case QVariant::Time:
            return value.toDate().toString("\'hh:mm:ss\'");

        case QVariant::Bool:
            return (value.toBool()) ? "true" : "false";

        default:
            return QString("'") + value.toString() + "'";
    }
}

QString DefaultDatabaseFormatter::getFormattedTableName(const QString &tablename) const
{
    return QString("\"") + tablename + "\"";
}
