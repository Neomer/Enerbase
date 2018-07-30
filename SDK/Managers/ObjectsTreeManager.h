#ifndef OBJECTSTREEMANAGER_H
#define OBJECTSTREEMANAGER_H

#include <QVector>

#include <SDK/BasicTypes.h>
#include <SDK/Defines.h>

#include <SDK/Database/AbstractDatabaseProvider.h>
#include <SDK/Model/ObjectsTreeModel.h>

class ObjectsTreeManager
{
    SINGLETON(ObjectsTreeManager)

public:
    QVector<std::shared_ptr<ObjectsTreeModel>> getChildObjects(const ObjectsTreeModel &model, const AbstractDatabaseProvider &provider);
};

#endif // OBJECTSTREEMANAGER_H
