#include "EmptyListReadException.h"

EmptyListReadException::EmptyListReadException() :
    BaseException()
{

}

EmptyListReadException::EmptyListReadException(QString message) :
    BaseException(message)
{

}

EmptyListReadException::EmptyListReadException(const char *message) :
    BaseException(message)
{

}
