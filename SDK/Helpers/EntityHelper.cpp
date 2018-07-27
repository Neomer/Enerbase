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

void EntityHelper::GetFields(const AbstractEntity *entity, QStringList &fields, char quote, bool recursievly) const
{
    GetFieldsPrivate(entity->metaObject(), fields, quote, recursievly);
}

void EntityHelper::GetProperties(const AbstractEntity *entity, PropertyList &properties)
{
    GetPropertiesPrivate(entity, entity->metaObject(), properties);
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

void EntityHelper::GetFieldsPrivate(const QMetaObject *metaObject, QStringList &fields, char quote, bool recursievly) const
{
    if (metaObject->superClass() != 0 && strcmp(metaObject->superClass()->className(), "QObject"))
    {
        GetFieldsPrivate(metaObject->superClass(), fields, quote, recursievly);
    }

    for (auto i = metaObject->propertyOffset(); i < metaObject->propertyCount(); i++)
    {
        auto metaProperty = metaObject->property(i);
        if (!metaProperty.isStored())
        {
            continue;
        }
        if (quote != 0)
        {
            int l = strlen(metaProperty.name());
            char f[l + 3];
            f[0] = quote;
            f[l + 1] = quote;
            f[l + 2] = 0;
            memcpy(f + 1, metaProperty.name(), l);

            fields << f;
        }
        else
        {
            fields << metaProperty.name();
        }
    }

}

void EntityHelper::GetPropertiesPrivate(const AbstractEntity *entity, const QMetaObject *metaObject, PropertyList &properties)
{
    if (metaObject->superClass() != 0 && strcmp(metaObject->superClass()->className(), "QObject"))
    {
        GetPropertiesPrivate(entity, metaObject->superClass(), properties);
    }

    for (auto i = metaObject->propertyOffset(); i < metaObject->propertyCount(); i++)
    {
        auto metaProperty = metaObject->property(i);
        if (!metaProperty.isStored())
        {
            continue;
        }
        if (!metaProperty.isReadable())
        {
            continue;
        }
        properties << QPair<QString, QVariant>(QString(metaProperty.name()), metaProperty.read(entity));
    }
}
