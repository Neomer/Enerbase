#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

#include <QObject>
#include <QUuid>

#include <SDK/BasicTypes.h>
#include <SDK/Defines.h>
#include <SDK/Database/AbstractDatabaseQuery.h>

#include "EntityMetadata.h"

#define ORM_METAOBJECT      \
    protected: \
        EntityMetadata _metadata; \
    public: \
        const EntityMetadata &metadata() { return _metadata; }  \
    protected:  \
    virtual void registerORMmethods() { }

#define ORM_REGISTER(method, bindname)           \
    _metadata.registerWriteMethod("##bindname", std::bind(method, this, std::tr1::placeholders::_1));


class SDKSHARED_EXPORT AbstractEntity :
        public QObject
{
    Q_OBJECT

    ORM_METAOBJECT

public:
    explicit AbstractEntity(QObject *parent = nullptr);

    virtual const char *getTableName() const = 0;
    virtual bool isValid() const = 0;

    bool isNew() const;
    bool hasChanges() const;

signals:
    void HasChangesChanged(bool value);

protected:
    void setIsNew(bool value);
    void setHasChanges(bool value);

private:
    bool _isNew, _hasChanges;
};

#endif // ABSTRACTENTITY_H
