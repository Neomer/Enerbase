#ifndef PROPERTYREADWRITEEXCEPTION_H
#define PROPERTYREADWRITEEXCEPTION_H

#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>
#include "EntityBaseException.h"

class SDKSHARED_EXPORT PropertyReadWriteException : public EntityBaseException
{
public:
    PropertyReadWriteException(const AbstractEntity *entity, QString propertyName);
    PropertyReadWriteException(const AbstractEntity *entity, QString propertyName, const char *message);
    PropertyReadWriteException(const AbstractEntity *entity, QString propertyName, QString message);

private:
    QString _propertyName;
};

#endif // PROPERTYREADWRITEEXCEPTION_H
