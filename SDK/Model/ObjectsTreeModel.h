#ifndef OBJECTSTREEMODEL_H
#define OBJECTSTREEMODEL_H

#include <QObject>
#include "AbstractIdentifiedEntity.h"

class SDKSHARED_EXPORT ObjectsTreeModel : public AbstractIdentifiedEntity
{
    Q_OBJECT

    Q_PROPERTY(QString Name READ getName WRITE setName NOTIFY NameChanged STORED true)
    Q_PROPERTY(QUuid ParentObjectUid READ getParentObjectUid WRITE setParentObjectUid NOTIFY ParentObjectUidChanged STORED true)

    QString m_Name;
    QUuid m_ParentObjectUid;

public:
    ObjectsTreeModel(QUuid uid = QUuid(), QString name = QString(), QUuid parentObjectUid = QUuid(), QObject *parent = nullptr);
    QString getName() const;
    QUuid getParentObjectUid() const;

public slots:
    void setName(QString Name);
    void setParentObjectUid(QUuid ParentObjectUid);

signals:
    void NameChanged(QString Name);
    void ParentObjectUidChanged(QUuid ParentObject);

    // AbstractEntity interface
public:
    virtual const char *getTableName() const override { return "ObjectsTree"; }

};

#endif // OBJECTSTREEMODEL_H
