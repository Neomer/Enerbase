#include "PostgreSQLQuery.h"

PostgreSQLQuery::PostgreSQLQuery(const AbstractDatabaseProvider *provider, PGresult *result) :
    BaseDatabaseQuery(),
    _result(result)
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

}

void PostgreSQLQuery::fields(QStringList &result)
{

}

int PostgreSQLQuery::rowCount()
{
    return PQntuples(_result);
}

int PostgreSQLQuery::fieldsCount()
{
    return 0;
}

QVariant PostgreSQLQuery::value(int index)
{
    return QVariant();
}

QVariant PostgreSQLQuery::value(const char *name)
{
    return QVariant();
}

bool PostgreSQLQuery::isValid()
{
    return false;
}

bool PostgreSQLQuery::isEmpty()
{
    return PQresultStatus(_result) == PGRES_EMPTY_QUERY;
}
