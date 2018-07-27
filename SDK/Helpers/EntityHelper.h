#ifndef ENTITYHELPER_H
#define ENTITYHELPER_H

#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>
#include <SDK/Database/AbstractDatabaseQuery.h>
#include <SDK/Database/AbstractDatabaseProvider.h>
#include <SDK/Model/AbstractEntity.h>
#include <SDK/Model/AbstractIdentifiedEntity.h>

class SDKSHARED_EXPORT EntityHelper
{
    SINGLETON(EntityHelper)

public:
    void Load(const AbstractDatabaseQuery *query, AbstractEntity *entity) const;
    void GetById(QUuid id, AbstractIdentifiedEntity *entity, AbstractDatabaseProvider *provider) const;

};

#endif // ENTITYHELPER_H
