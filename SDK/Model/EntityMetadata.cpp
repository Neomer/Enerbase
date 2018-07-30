#include "EntityMetadata.h"

#include <SDK/Exceptions/NotFoundException.h>

EntityMetadata::EntityMetadata()
{

}

void EntityMetadata::registerMethod(const char *name, Event *event)
{
    _methods_write.insert(std::pair<const char *, Event *>(name, event));
}


