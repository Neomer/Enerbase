#include <QDebug>

#include "AbstractIdentifiedEntity.h"
#include <SDK/Helpers/EntityHelper.h>
#include <SDK/Exceptions/NotFoundException.h>

AbstractIdentifiedEntity::AbstractIdentifiedEntity() :
    AbstractEntity(),
    _valid(false)
{

}

QUuid AbstractIdentifiedEntity::getId() const
{
    return m_Id;
}

void AbstractIdentifiedEntity::getById(const QUuid &id, const AbstractDatabaseProvider *provider)
{
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
    EntityHelper::PropertyList prop;
    EntityHelper::Instance().GetProperties(this, prop);

    QString sql;

    if (isNew())
    {
        for (int i = 0; i < prop.count(); ++i)
        {
            auto p = prop.at(i);

        }
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

void AbstractIdentifiedEntity::setIsValid(bool value)
{
    if (_valid == value)
    {
        return;
    }
    _valid = value;
    emit ValidChanged(value);
}
