#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

#include <QObject>
#include <QUuid>

#include <SDK/BasicTypes.h>
#include <SDK/Defines.h>
#include <SDK/Database/AbstractDatabaseQuery.h>


class AbstractEntity :
        public QObject
{
    Q_OBJECT

public:
    explicit AbstractEntity(QObject *parent = nullptr);

};

#endif // ABSTRACTENTITY_H
