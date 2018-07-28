//#include <catalog/pg_type.h>

#include <QUuid>
#include <QDateTime>

#include <SDK/Helpers/StringHelper.h>
#include <SDK/Exceptions/OutOfRangeException.h>
#include <SDK/Exceptions/DataFormatException.h>

#include "PostgreSQLQuery.h"

PostgreSQLQuery::PostgreSQLQuery(const AbstractDatabaseProvider *provider, PGresult *result) :
    BaseDatabaseQuery(),
    _result(result),
    _provider(provider)
{
    if (PQresultStatus(result) == PGRES_BAD_RESPONSE ||
        PQresultStatus(result) == PGRES_NONFATAL_ERROR ||
        PQresultStatus(result) == PGRES_FATAL_ERROR)
    {
        throw DatabaseQueryBaseException(provider, PQresultErrorMessage(result));
    }
}

void PostgreSQLQuery::close()
{
    PQclear(_result);
}

void PostgreSQLQuery::fields(QStringList &result) const
{
    for (auto i = 0; i < fieldsCount(); i++)
    {
        result << PQfname(_result, i);
    }
}

int PostgreSQLQuery::rowCount() const
{
    return PQntuples(_result);
}

bool PostgreSQLQuery::hasField(const char *name) const
{
    return field(name) >= 0;
}

i32 PostgreSQLQuery::field(const char *name) const
{
    auto result = PQfnumber(_result, name);
    if (result == -1 && name[0] != '"')
    {
        auto l = strlen(name);
        char c_name[l + 3];
        c_name[0] = c_name[l + 1] = '"';
        c_name[l + 2] = 0;
        memcpy(c_name + 1, name, l);

        result = PQfnumber(_result, c_name);
    }
    return result;
}

int PostgreSQLQuery::fieldsCount() const
{
    return PQnfields(_result);
}

QVariant PostgreSQLQuery::value(int index) const
{
    if (index < 0 || index >= fieldsCount())
    {
        throw OutOfRangeException("Column index out of range!");
    }

    QVariant ret;
    getFormattedValue(
                PQgetvalue(_result, getCurrentRow(), index),
                PQftype(_result, index),
                ret);
    return ret;
}

QVariant PostgreSQLQuery::value(const char *name) const
{
    return value(field(name));
}

bool PostgreSQLQuery::isValid() const
{
    return false;
}

void PostgreSQLQuery::getFormattedValue(const char *c_value, Oid type_id, QVariant &value) const
{
    QString s(c_value);
    bool ok;

    switch (type_id)
    {
        case 21:   // INT2OID
        case 23:   // INT4OID
        case 20:   // INT8OID
        case 1700: // NUMERICOID
            value = QVariant::fromValue(s.toLongLong(&ok));
            if (!ok)
            {
                throw DataFormatException();
            }
            break;

        case 16:   // BOOLOID
            value = QVariant::fromValue(s.toLower() == "true" || s.toLower() == "1" || s.toLower() == "t");
            break;

        case 2950: // UUIDOID
            value = QVariant::fromValue(QUuid(s));
            break;

        case 17:   // BYTEAOID
        case 18:   // CHAROID
        case 25:   // TEXTOID
        case 194:  // PGNODETREEOID
        case 829:  // MACADDROID
        case 774:  // MACADDR8OID
        case 869:  // INETOID
        case 650:  // CIDROID
        case 1042: // BPCHAROID
        case 1043: // VARCHAROID
            value = QVariant::fromValue(s);
            break;

        case 700: // FLOAT4OID
        case 701: // FLOAT8OID
        case 790: // CASHOID
            value = QVariant::fromValue(s.toDouble(&ok));
            if (!ok)
            {
                throw DataFormatException();
            }
            break;

        case 1082: // DATEOID
            value = QVariant::fromValue(QDateTime::fromString(s, "yyyy-MM-dd"));
            break;

        case 1083: // TIMEOID
            value = QVariant::fromValue(QDateTime::fromString(s, "hh:mm:ss"));
            break;

        case 1114: // TIMESTAMPOID
            value = QVariant::fromValue(QDateTime::fromString(s, "yyyy-MM-dd hh:mm:ss"));
            break;

        case 1270: // TIMETZOID
        case 1184: // TIMESTAMPTZOID
            throw DatabaseException(_provider, QString("Fields types with timezone is unsupported yet!"));

        case 1187: // INTERVALOID
            value = QVariant::fromValue(QDateTime::fromString(s, "hh:mm:ss"));
            break;

        default:
            throw DatabaseException(_provider, QString("Unsupported type! OID: %1").arg(QString::number(type_id)));
    }
}
