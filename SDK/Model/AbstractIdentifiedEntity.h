#ifndef ABSTRACTIDENTIFIEDENTITY_H
#define ABSTRACTIDENTIFIEDENTITY_H

#include <QUuid>
#include <QVector>
#include <QPair>
#include <QVariant>

#include <SDK/Model/AbstractEntity.h>
#include <SDK/Database/AbstractDatabaseProvider.h>

class SDKSHARED_EXPORT AbstractIdentifiedEntity : public AbstractEntity
{
    Q_OBJECT

    QUuid m_Id;

public:
    AbstractIdentifiedEntity(QUuid uid = QUuid(), QObject *parent = nullptr);

    QUuid getId() const;

    virtual void getById(const QUuid &id, const AbstractDatabaseProvider *provider = nullptr);
    virtual void save(const AbstractDatabaseProvider *provider = nullptr);
    virtual void remove(const AbstractDatabaseProvider *provider = nullptr);

public slots:
    void setId(QUuid Id);

signals:
    void IdChanged(QUuid Id);
    void ValidChanged(bool valid);

    // AbstractEntity interface
public:
    virtual bool isValid() const override;
    virtual void registerORMmethods() override;

private:
    bool _valid;

protected:
    void setIsValid(bool value);

    virtual void getPropertyList(QVector<QPair<QString, QVariant>> &list);
};

#endif // ABSTRACTIDENTIFIEDENTITY_H
