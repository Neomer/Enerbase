#include "AbstractDatabaseQuery.h"
#include <Helpers/StringHelper.h>

AbstractDatabaseQuery::AbstractDatabaseQuery()
{

}

AbstractDatabaseQuery::~AbstractDatabaseQuery()
{

}

QVariant AbstractDatabaseQuery::value(QString name) const
{
    char *c_name = new char[StringHelper::StringLength(name)];
    StringHelper::StringToConstChar(name, c_name);
    auto ret = value(c_name);
    delete [] c_name;
    return ret;
}
