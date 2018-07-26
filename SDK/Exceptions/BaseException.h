#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <QString>
#include <exception>
#include "../sdk_global.h"

class SDKSHARED_EXPORT BaseException : public std::exception
{
public:
    BaseException();
    BaseException(QString message);
    BaseException(const char *message);

private:
    std::string _message;

    // exception interface
public:
    virtual const char* what() const throw()
    {
        return _message.c_str();
    }

};

#endif // BASEEXCEPTION_H
