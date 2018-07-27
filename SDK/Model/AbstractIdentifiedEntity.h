#ifndef ABSTRACTIDENTIFIEDENTITY_H
#define ABSTRACTIDENTIFIEDENTITY_H

#include <QUuid>

#include <SDK/Model/AbstractEntity.h>
#include <SDK/Database/AbstractDatabaseProvider.h>

class SDKSHARED_EXPORT AbstractIdentifiedEntity : public AbstractEntity
{
    Q_OBJECT

    Q_PROPERTY(QUuid Id READ getId WRITE setId NOTIFY IdChanged)

    QUuid m_Id;

public:
    AbstractIdentifiedEntity();

    QUuid getId() const;

    virtual void getById(const QUuid &id, const AbstractDatabaseProvider *provider);

public slots:
    void setId(QUuid Id);

signals:
    void IdChanged(QUuid Id);
};

#endif // ABSTRACTIDENTIFIEDENTITY_H
