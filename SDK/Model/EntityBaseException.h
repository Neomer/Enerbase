#ifndef ENTITYBASEEXCEPTION_H
#define ENTITYBASEEXCEPTION_H

#include "AbstractEntity.h"
#include <Exceptions/BaseException.h>

class SDKSHARED_EXPORT EntityBaseException : public BaseException
{
public:
    EntityBaseException(const AbstractEntity *entity);
    EntityBaseException(const AbstractEntity *entity, const char *message);
    EntityBaseException(const AbstractEntity *entity, QString message);

    const AbstractEntity *getEntity() { return _entity; }

private:
    const AbstractEntity *_entity;
};

#endif // ENTITYBASEEXCEPTION_H
