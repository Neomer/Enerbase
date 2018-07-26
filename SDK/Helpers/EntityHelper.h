#ifndef ENTITYHELPER_H
#define ENTITYHELPER_H

#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>
#include <SDK/Database/AbstractDatabaseQuery.h>
#include <SDK/Database/AbstractDatabaseProvider.h>
#include <SDK/Model/AbstractEntity.h>

class SDKSHARED_EXPORT EntityHelper
{
    SINGLETON(EntityHelper)

public:
    void Load(const AbstractDatabaseQuery *query, AbstractEntity *entity) const;
};

#endif // ENTITYHELPER_H
