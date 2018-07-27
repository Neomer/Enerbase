#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

#include <QObject>
#include <QUuid>

#include <SDK/BasicTypes.h>
#include <SDK/Defines.h>
#include <SDK/Database/AbstractDatabaseQuery.h>


class SDKSHARED_EXPORT AbstractEntity :
        public QObject
{
    Q_OBJECT

public:
    explicit AbstractEntity(QObject *parent = nullptr);

    virtual const char *getTableName() const = 0;
};

#endif // ABSTRACTENTITY_H
