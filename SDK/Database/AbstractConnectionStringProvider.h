#ifndef ABSTRACTCONNECTIONSTRINGPROVIDER_H
#define ABSTRACTCONNECTIONSTRINGPROVIDER_H


class AbstractConnectionStringProvider
{
public:
    AbstractConnectionStringProvider() = default;

    virtual QString toString() const = 0;
};

#endif // ABSTRACTCONNECTIONSTRINGPROVIDER_H
