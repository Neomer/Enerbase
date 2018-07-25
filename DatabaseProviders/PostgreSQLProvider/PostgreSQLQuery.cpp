#include "PostgreSQLQuery.h"

PostgreSQLQuery::PostgreSQLQuery(PGresult *result) :
    AbstractDatabaseQuery(),
    _result(result)
{

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
    return 0;
}

int PostgreSQLQuery::fieldsCount()
{
    return 0;
}

QVariant PostgreSQLQuery::value()
{
    return QVariant();
}
