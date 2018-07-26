#include "OutOfRangeException.h"

OutOfRangeException::OutOfRangeException() :
    BaseException()
{

}

OutOfRangeException::OutOfRangeException(QString message) :
    BaseException(message)
{

}

OutOfRangeException::OutOfRangeException(const char *message) :
    BaseException(message)
{

}
