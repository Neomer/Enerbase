#ifndef POSTGRESQLCONNECTIONSTRINGPROVIDER_H
#define POSTGRESQLCONNECTIONSTRINGPROVIDER_H

#include <QString>

#include "postgresql_global.h"
#include <SDK/BasicTypes.h>
#include <SDK/Defines.h>
#include <SDK/Database/AbstractConnectionStringProvider.h>

class POSTGRESQLSHARED_EXPORT PostgreSQLConnectionStringProvider : public AbstractConnectionStringProvider
{
public:
    PostgreSQLConnectionStringProvider();

    PROP(QString, Host)
    PROP(ui16, Port)
    PROP(QString, Username)
    PROP(QString, Password)
    PROP(QString, Database)

    // AbstractConnectionStringProvider interface
public:
    virtual QString toString() const override;
};

#endif // POSTGRESQLCONNECTIONSTRINGPROVIDER_H
