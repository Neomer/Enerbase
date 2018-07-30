#include "ObjectsTreeManager.h"

#include <SDK/Helpers/EntityHelper.h>

ObjectsTreeManager::ObjectsTreeManager()
{

}

QVector<std::shared_ptr<ObjectsTreeModel> > ObjectsTreeManager::getChildObjects(const ObjectsTreeModel &model, const AbstractDatabaseProvider &provider)
{
    auto query = provider.exec(QString("select * from %1.%2 where %3=%4;").arg(
                                   provider.getFormatter()->getFormattedTableName("Enerbase"),
                                   provider.getFormatter()->getFormattedTableName(model.getTableName()),
                                   provider.getFormatter()->getFormattedFieldName("ParentObject"),
                                   provider.getFormatter()->getFormattedValue(model.getId())));

    QVector<std::shared_ptr<ObjectsTreeModel>> ret;

    if (!query->isEmpty())
    {
        do
        {
            auto obj = new ObjectsTreeModel();
            EntityHelper::Instance().Load(query.get(), obj);
            ret << std::shared_ptr<ObjectsTreeModel>(obj);
        }
        while (query->next());
    }

    return ret;

}
