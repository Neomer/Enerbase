#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <Defines.h>

#include <QJsonObject>

class IJsonSerializable
{
public:
    virtual ~IJsonSerializable() { }

    virtual void toJson(QJsonObject &object) = 0;
    virtual void fromJson(const QJsonObject &object) = 0;
};

#endif // IJSONSERIALIZABLE_H
