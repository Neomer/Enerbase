#include <QMetaObject>
#include <QMetaProperty>

#include "EntityHelper.h"

EntityHelper::EntityHelper()
{

}

void EntityHelper::Load(const AbstractDatabaseQuery *query, AbstractEntity *entity)
{
    const QMetaObject *metaObject = entity->metaObject();
}
