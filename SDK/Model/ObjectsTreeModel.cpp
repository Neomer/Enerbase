#include "ObjectsTreeModel.h"

ObjectsTreeModel::ObjectsTreeModel(QUuid uid, QString name, QUuid parentObjectUid, QObject *parent) :
    AbstractIdentifiedEntity(uid, parent),
    m_Name(name),
    m_ParentObjectUid(parentObjectUid)
{

}

QString ObjectsTreeModel::getName() const
{
    return m_Name;
}

QUuid ObjectsTreeModel::getParentObjectUid() const
{
    return m_ParentObjectUid;
}

void ObjectsTreeModel::setName(QString Name)
{
    if (m_Name == Name)
        return;

    m_Name = Name;
    emit NameChanged(m_Name);
}

void ObjectsTreeModel::setParentObjectUid(QUuid ParentObjectUid)
{
    if (m_ParentObjectUid == ParentObjectUid)
        return;

    m_ParentObjectUid = ParentObjectUid;
    emit ParentObjectUidChanged(m_ParentObjectUid);
}

