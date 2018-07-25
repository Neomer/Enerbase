#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <QVector>

#include <SDK/sdk_global.h>
#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>

#include <SDK/Database/AbstractDatabaseProvider.h>

class SDKSHARED_EXPORT DatabaseHelper
{
    SINGLETON(DatabaseHelper)

public:
    void registerProvider(AbstractDatabaseProvider *provider, bool isActive = true);
    AbstractDatabaseProvider *getActiveProvider();

private:
    QVector<AbstractDatabaseProvider *> _providers;
};

#endif // DATABASEHELPER_H
