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
    auto result = provider->exec(QString("select * from \"Enerbase\".\"" + QString(getTableName()) + "\" where \"Id\"='" + id.toString() + "' limit 1;"));
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
    if (isNew())
    {
        QStringList fields;
        EntityHelper::Instance().GetFields(this, fields, '"');

        QString sql("insert into \"Enerbase\".\"" + QString(getTableName()) + "\" (" + fields.join(',') + ") values ();");
        qDebug() << sql;
    }
    else
    {

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
