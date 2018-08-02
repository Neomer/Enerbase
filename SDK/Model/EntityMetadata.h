#ifndef ABSTRACTENTITYEX_H
#define ABSTRACTENTITYEX_H

#include <QVariant>
#include <QDebug>

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

#ifdef __MINGW
#include <tr1/functional>
#include <tr1/memory>
#include <bits/unique_ptr.h>
#else
#include <memory>
#include <functional>
#include <utility>
#endif

#include <SDK/Model/Event.h>
#include <SDK/Model/MetadataEventCallException.h>
#include <SDK/Exceptions/NotFoundException.h>
#include <SDK/sdk_global.h>


class SDKSHARED_EXPORT EntityMetadata
{
public:
    EntityMetadata();

    void registerMethod(const char *name, MetaMethod *event);
    std::vector<const char *> getMethods(MetaMethod::EventType type) const;

    template<typename... Args>
    void write(const char *name, Args ...args) const
    {
        for (auto e : _methods)
        {
            if (!strcmp(e.first, name))
            {
                auto event = e.second;
                try {
                    (*event).invoke(args...);
                } catch (MetadataEventCallException &) {
                    continue;
                }
                return;
            }
        }
        throw NotFoundException();
    }

    template<typename Rt>
    Rt read(const char *name) const
    {
        for (auto e : _methods)
        {
            if (!strcmp(e.first, name))
            {
                auto event = e.second;
                try {
                    auto result = (*event).invoke<Rt>();
                    return result;
                } catch (MetadataEventCallException &) {
                    continue;
                }
            }
        }
        throw NotFoundException();
    }

private:
    std::multimap<const char *, MetaMethod *> _methods;
};

#endif // ABSTRACTENTITYEX_H
