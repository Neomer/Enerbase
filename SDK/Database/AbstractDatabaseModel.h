#ifndef ABSTRACTDATABASEMODEL_H
#define ABSTRACTDATABASEMODEL_H

#include "sdk_global.h"
#include <QAbstractItemModel>


class SDKSHARED_EXPORT AbstractDatabaseModel : public QObject
{
    Q_OBJECT

public:
    AbstractDatabaseModel(QObject * parent = nullptr);
};

#endif // ABSTRACTDATABASEMODEL_H
