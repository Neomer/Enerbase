#include "BaseException.h"

BaseException::BaseException() :
    QException()
{

}

BaseException::BaseException(QString message) :
    _message(message)
{

}

BaseException::BaseException(const char *message) :
    _message(message)
{

}

QString BaseException::getMessage()
{
    return _message;
}

void BaseException::raise() const
{

}

QException *BaseException::clone() const
{
    return new BaseException();
}
