#ifndef ABSTRACTDATABASEMODEL_H
#define ABSTRACTDATABASEMODEL_H

#include "../sdk_global.h"
#include <QAbstractItemModel>
#include <QUuid>

class SDKSHARED_EXPORT AbstractDatabaseModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUuid Id READ getId WRITE setId NOTIFY IdChanged)

    QUuid m_Id;

public:
    AbstractDatabaseModel(QObject * parent = nullptr);
    virtual ~AbstractDatabaseModel();
    QUuid getId() const
    {
        return m_Id;
    }

public slots:
    void setId(QUuid Id)
    {
        if (m_Id == Id)
            return;

        m_Id = Id;
        emit IdChanged(m_Id);
    }

signals:
    void IdChanged(QUuid Id);
};

#endif // ABSTRACTDATABASEMODEL_H
