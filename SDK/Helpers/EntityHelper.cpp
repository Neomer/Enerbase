#include <QMetaObject>
#include <QMetaProperty>

#include <SDK/Exceptions/DataFormatException.h>
#include <SDK/Model/PropertyReadWriteException.h>

#include "EntityHelper.h"


EntityHelper::EntityHelper()
{

}

void EntityHelper::Load(const AbstractDatabaseQuery *query, AbstractEntity *entity) const
{
    const QMetaObject *metaObject = entity->metaObject();
    for (auto i = metaObject->propertyOffset(); i < metaObject->propertyCount(); i++)
    {
        auto metaProperty = metaObject->property(i);
        if (!metaProperty.isWritable() || metaProperty.isConstant())
        {
            continue;
        }
        if (!query->hasField(metaProperty.name()))
        {
            continue;
        }
        try
        {
            auto value = query->value(metaProperty.name());
            if (!value.isValid())
            {
                continue;
            }
            if (!metaProperty.write(entity, value))
            {
                throw PropertyReadWriteException(entity, metaProperty.name());
            }
        }
        catch (DataFormatException &)
        {
            continue;
        }
    }
}
