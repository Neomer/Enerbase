#include "PostgreSQLQuery.h"

PostgreSQLQuery::PostgreSQLQuery(const AbstractDatabaseProvider *provider, PGresult *result) :
    AbstractDatabaseQuery(),
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

bool PostgreSQLQuery::first()
{
    return false;
}

bool PostgreSQLQuery::last()
{
    return false;
}

bool PostgreSQLQuery::next()
{
    return false;
}

bool PostgreSQLQuery::prev()
{
    return false;
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

QVariant PostgreSQLQuery::value()
{
    return QVariant();
}

bool PostgreSQLQuery::isValid()
{

}

bool PostgreSQLQuery::isEmpty()
{
    return PQresultStatus(_result) == PGRES_EMPTY_QUERY;
}
