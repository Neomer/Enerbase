#include "NotNullException.h"

NotNullException::NotNullException() :
    BaseException("Unexpected null pointer!")
{

}

NotNullException::NotNullException(QString message) :
    BaseException(message)
{

}

NotNullException::NotNullException(const char *message) :
    BaseException(message)
{

}
