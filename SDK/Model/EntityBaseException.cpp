#include "EntityBaseException.h"

EntityBaseException::EntityBaseException(const AbstractEntity *entity) :
    BaseException(),
    _entity(entity)
{

}

EntityBaseException::EntityBaseException(const AbstractEntity *entity, const char *message) :
    BaseException(message),
    _entity(entity)
{

}

EntityBaseException::EntityBaseException(const AbstractEntity *entity, QString message) :
    BaseException(message),
    _entity(entity)
{

}
