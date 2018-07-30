#include "AbstractEntity.h"
#include <functional>
#include <map>
#include <memory>
#include <typeindex>

AbstractEntity::AbstractEntity(QObject *parent) :
    QObject(parent),
    _isNew(true)
{

}

bool AbstractEntity::isNew() const
{
    return _isNew;
}

bool AbstractEntity::hasChanges() const
{
    return _hasChanges;
}

void AbstractEntity::setIsNew(bool value)
{
    if (value == _isNew)
    {
        return;
    }
    _isNew = value;
}

void AbstractEntity::setHasChanges(bool value)
{
    if (value == _hasChanges)
    {
        return;
    }
    _hasChanges = value;
    emit HasChangesChanged(value);
}
