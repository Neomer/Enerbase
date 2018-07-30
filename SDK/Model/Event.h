#ifndef EVENT_H
#define EVENT_H

#include <functional>
#include <string>
#include <memory>
#include <unordered_map>

#include <SDK/Model/MetadataEventCallException.h>

class Event
{
private:
    struct base
    {
        virtual ~base() { }
    };
    template <typename Rt, typename... Args>
    struct wrapped : base
    {
        typedef std::function<Rt(Args...)> func_type;
        func_type f;
        wrapped(func_type aFunc) :
            f(aFunc)
        {

        }
    };
    std::unique_ptr<base> p_base;

public:
    template <typename Rt, typename... Args>
    Event(std::function<Rt(Args...)> aFunc) :
        p_base(new wrapped<Rt, Args...>(aFunc))
    {

    }

    template <typename Rt, typename... Args>
    Event& operator=(std::function<Rt(Args...)> aFunc)
    {
        p_base = std::unique_ptr<base>(new wrapped<Rt, Args...>(aFunc));
        return *this;
    }

    template <typename... Args>
    void invoke(Args... args) const
    {
        auto p_wrapped = dynamic_cast< wrapped<void, Args...>* >(p_base.get());
        if(p_wrapped)
        {
            p_wrapped->f(args...);
        }
        else
        {
            throw MetadataEventCallException();
        }
    }

    template <typename Rt>
    Rt invoke() const
    {
        auto p_wrapped = dynamic_cast< wrapped<Rt>* >(p_base.get());
        if(p_wrapped)
        {
            return p_wrapped->f();
        }
        else
        {
            throw MetadataEventCallException();
        }
    }
};

#endif // EVENT_H
