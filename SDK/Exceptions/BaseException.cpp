#include "BaseException.h"

BaseException::BaseException() :
    std::exception()
{

}

BaseException::BaseException(QString message) :
    std::exception(),
    _message(message.toStdString())
{

}

BaseException::BaseException(const char *message) :
    std::exception(),
    _message(message)
{

}
