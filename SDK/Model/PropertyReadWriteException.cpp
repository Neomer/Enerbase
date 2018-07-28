#include "PropertyReadWriteException.h"

PropertyReadWriteException::PropertyReadWriteException(const AbstractEntity *entity, QString propertyName) :
    EntityBaseException(entity),
    _propertyName(propertyName)
{

}

PropertyReadWriteException::PropertyReadWriteException(const AbstractEntity *entity, QString propertyName, const char * message) :
    EntityBaseException(entity, message),
    _propertyName(propertyName)
{

}

PropertyReadWriteException::PropertyReadWriteException(const AbstractEntity *entity, QString propertyName, QString message) :
    EntityBaseException(entity, message),
    _propertyName(propertyName)
{

}
