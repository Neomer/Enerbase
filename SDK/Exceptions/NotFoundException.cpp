#include "NotFoundException.h"

NotFoundException::NotFoundException() :
    BaseException()
{

}

NotFoundException::NotFoundException(QString message) :
    BaseException(message)
{

}

NotFoundException::NotFoundException(const char *message) :
    BaseException(message)
{

}
