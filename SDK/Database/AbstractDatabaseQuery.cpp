#include "AbstractDatabaseQuery.h"
#include <Helpers/StringHelper.h>

AbstractDatabaseQuery::AbstractDatabaseQuery()
{

}

AbstractDatabaseQuery::~AbstractDatabaseQuery()
{

}

QVariant AbstractDatabaseQuery::value(QString name)
{
    char c_name[StringHelper::StringLength(name)];
    StringHelper::StringToConstChar(name, c_name);
    return value(c_name);
}
