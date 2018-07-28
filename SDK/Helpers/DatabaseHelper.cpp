#include <QDebug>

#include "DatabaseHelper.h"
#include <SDK/Database/DatabaseException.h>

DatabaseHelper::DatabaseHelper()
{
    qDebug() << "Init DatabaseHelper";
}

DatabaseHelper::~DatabaseHelper()
{
    unregisterAll();
}

void DatabaseHelper::registerProvider(AbstractDatabaseProvider *provider, bool isActive)
{
    _providers.push_back(provider);
}

AbstractDatabaseProvider *DatabaseHelper::getActiveProvider()
{
    return (_providers.isEmpty()) ? nullptr : _providers.last();
}

AbstractDatabaseProvider *DatabaseHelper::getActiveProviderNotNull()
{
    if (_providers.isEmpty())
    {
        throw NotNullException();
    }
    return _providers.last();
}

void DatabaseHelper::unregisterAll()
{
    while (!_providers.isEmpty())
    {
        auto p = _providers.takeFirst();
        try
        {
            p->close();
        }
        catch (DatabaseException &)
        {

        }
        delete p;
    }
}
