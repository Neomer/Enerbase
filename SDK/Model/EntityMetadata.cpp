#include "EntityMetadata.h"

#include <SDK/Exceptions/NotFoundException.h>

EntityMetadata::EntityMetadata()
{

}

void EntityMetadata::registerMethod(const char *name, MetaMethod *event)
{
    _methods.insert(std::pair<const char *, MetaMethod *>(name, event));
}

std::vector<const char *> EntityMetadata::getMethods(MetaMethod::EventType type) const
{
    std::vector<const char *> ret;
    for (auto e : _methods)
    {
        if (e.second->Type() == type)
        {
            ret.push_back(e.first);
        }
    }
    return ret;
}


