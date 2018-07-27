#include <QMetaObject>
#include <QMetaProperty>

#include <SDK/Exceptions/DataFormatException.h>
#include <SDK/Model/PropertyReadWriteException.h>
#include <SDK/Exceptions/OutOfRangeException.h>
#include <SDK/Exceptions/NotNullException.h>

#include <SDK/Helpers/DatabaseHelper.h>
#include <SDK/Database/AbstractDatabaseProvider.h>

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
        catch (OutOfRangeException &)
        {
            continue;
        }
        catch (DataFormatException &)
        {
            continue;
        }
    }
}

void EntityHelper::GetById(QUuid id, AbstractIdentifiedEntity *entity, AbstractDatabaseProvider *provider) const
{
    try
    {
        auto result = provider->exec(QString("select * from \"Enerbase\".\"" + QString(entity->getTableName()) + "\" where \"Id\"='" + id.toString() + "' limit 1;"));
        Load(result.get(), entity);
    }
    catch (NotNullException &ex)
    {

    }
}
