#include <QDebug>

#include "AbstractIdentifiedEntity.h"

#include <SDK/Helpers/DatabaseHelper.h>
#include <SDK/Helpers/EntityHelper.h>
#include <SDK/Exceptions/NotFoundException.h>

#include <functional>

AbstractIdentifiedEntity::AbstractIdentifiedEntity(QUuid uid, QObject *parent) :
    AbstractEntity(parent),
    m_Id(uid),
    _valid(false)
{
    registerORMmethods();
}

QUuid AbstractIdentifiedEntity::getId() const
{
    return m_Id;
}

void AbstractIdentifiedEntity::getById(const QUuid &id, const AbstractDatabaseProvider *provider)
{
    if (provider == nullptr)
    {
        provider = DatabaseHelper::Instance().getActiveProviderNotNull();
    }

    auto result = provider->exec(QString("select * from %1.%2 where %3=%4 limit 1;").arg(
                                         provider->getFormatter()->getFormattedTableName(QString("Enerbase")),
                                         provider->getFormatter()->getFormattedTableName(QString(getTableName())),
                                         provider->getFormatter()->getFormattedFieldName("Id"),
                                         provider->getFormatter()->getFormattedValue(id)));
    if (result->isEmpty())
    {
        throw NotFoundException();
    }
    EntityHelper::Instance().Load(result.get(), this);
    setIsValid(true);
    setIsNew(false);
}

void AbstractIdentifiedEntity::save(const AbstractDatabaseProvider *provider)
{
    if (provider == nullptr)
    {
        provider = DatabaseHelper::Instance().getActiveProviderNotNull();
    }

    EntityHelper::PropertyList prop;
    getPropertyList(prop);

    QString sql;

    if (isNew())
    {
        QString fields, values;
        for (int i = 0; i < prop.count() - 1; ++i)
        {
            auto p = prop.at(i);
            fields.append(provider->getFormatter()->getFormattedFieldName(p.first) + ",");
            values.append(provider->getFormatter()->getFormattedValue(p.second) + ",");
        }
        fields.append(provider->getFormatter()->getFormattedFieldName(prop.at(prop.count() - 1).first));
        values.append(provider->getFormatter()->getFormattedValue(prop.at(prop.count() - 1).second));

        sql = QString("insert into %1.%2 (%3) values (%4);").arg(
                provider->getFormatter()->getFormattedTableName("Enerbase"),
                provider->getFormatter()->getFormattedTableName(getTableName()),
                fields,
                values);
    }
    else
    {
        QString values;
        for (int i = 0; i < prop.count() - 1; ++i)
        {
            auto p = prop.at(i);
            values.append(QString("%1=%2,").arg(
                              provider->getFormatter()->getFormattedFieldName(p.first),
                              provider->getFormatter()->getFormattedValue(p.second)));
        }
        values.append(QString("%1=%2").arg(
                          provider->getFormatter()->getFormattedFieldName(prop.at(prop.count() - 1).first),
                          provider->getFormatter()->getFormattedValue(prop.at(prop.count() - 1).second)));
        sql = QString("update %1.%2 set %3 where %4=%5;").arg(
                provider->getFormatter()->getFormattedTableName("Enerbase"),
                provider->getFormatter()->getFormattedTableName(getTableName()),
                values,
                provider->getFormatter()->getFormattedFieldName("Id"),
                provider->getFormatter()->getFormattedValue(getId()));
    }

    if (!sql.isEmpty())
    {
        provider->exec(sql);
    }
    setIsNew(false);
}

void AbstractIdentifiedEntity::remove(const AbstractDatabaseProvider *provider)
{
    if (provider == nullptr)
    {
        provider = DatabaseHelper::Instance().getActiveProviderNotNull();
    }

    provider->exec(QString("delete from %1.%2 where %3=%4 limit 1;").arg(
                       provider->getFormatter()->getFormattedTableName("Enerbase"),
                       provider->getFormatter()->getFormattedTableName(getTableName()),
                       provider->getFormatter()->getFormattedFieldName("Id"),
                       provider->getFormatter()->getFormattedValue(getId())));
    setIsNew(true);
}

void AbstractIdentifiedEntity::setId(QUuid Id)
{
    if (m_Id == Id)
    {
        return;
    }

    m_Id = Id;
    emit IdChanged(m_Id);
}

bool AbstractIdentifiedEntity::isValid() const
{
    return _valid;
}

void AbstractIdentifiedEntity::registerORMmethods()
{
    AbstractEntity::registerORMmethods();

    _metadata.registerMethod("Id", new Event(std::function<void(QUuid)>(std::bind(&AbstractIdentifiedEntity::setId, this, std::placeholders::_1))));
    _metadata.registerMethod("Id", new Event(std::function<QUuid(void)>(std::bind(&AbstractIdentifiedEntity::getId, this))));
}

void AbstractIdentifiedEntity::setIsValid(bool value)
{
    if (_valid == value)
    {
        return;
    }
    _valid = value;
    emit ValidChanged(value);
}

void AbstractIdentifiedEntity::getPropertyList(QVector<QPair<QString, QVariant> > &list)
{
    EntityHelper::Instance().GetProperties(this, list);
}
