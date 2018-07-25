#include "DatabaseHelper.h"

DatabaseHelper::DatabaseHelper()
{

}

void DatabaseHelper::registerProvider(AbstractDatabaseProvider *provider, bool isActive)
{
    _providers.push_back(provider);
}

AbstractDatabaseProvider *DatabaseHelper::getActiveProvider()
{
    return (_providers.isEmpty()) ? nullptr : _providers.last();
}
