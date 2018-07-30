#include "AbstractDatabaseProvider.h"
#include <Helpers/StringHelper.h>

AbstractDatabaseProvider::AbstractDatabaseProvider()
{

}

AbstractDatabaseProvider::AbstractDatabaseProvider(const AbstractDatabaseProvider &other)
{

}

AbstractDatabaseProvider &AbstractDatabaseProvider::operator =(const AbstractDatabaseProvider &other)
{
    return *this;
}

AbstractDatabaseProvider::~AbstractDatabaseProvider()
{

}

std::shared_ptr<AbstractDatabaseQuery> AbstractDatabaseProvider::exec(const QStringView &sql) const
{
    char *cs = new char[StringHelper::StringLength(sql)];
    StringHelper::StringToConstChar(sql, cs);
    auto ret = exec(cs);
    delete [] cs;
    return ret;
}
