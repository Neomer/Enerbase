#include "AbstractIdentifiedEntity.h"
#include <SDK/Helpers/EntityHelper.h>


AbstractIdentifiedEntity::AbstractIdentifiedEntity()
{

}

QUuid AbstractIdentifiedEntity::getId() const
{
    return m_Id;
}

void AbstractIdentifiedEntity::getById(const QUuid &id, const AbstractDatabaseProvider *provider)
{
    auto result = provider->exec(QString("select * from \"Enerbase\".\"" + QString(getTableName()) + "\" where \"Id\"='" + id.toString() + "' limit 1;"));
    EntityHelper::Instance().Load(result.get(), this);
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
