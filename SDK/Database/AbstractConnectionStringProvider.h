#ifndef ABSTRACTCONNECTIONSTRINGPROVIDER_H
#define ABSTRACTCONNECTIONSTRINGPROVIDER_H

#include <SDK/sdk_global.h>

class SDKSHARED_EXPORT AbstractConnectionStringProvider
{
public:
    AbstractConnectionStringProvider() = default;

    virtual QString toString() const = 0;
};

#endif // ABSTRACTCONNECTIONSTRINGPROVIDER_H
