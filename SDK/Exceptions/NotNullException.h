#ifndef NOTNULLEXCEPTION_H
#define NOTNULLEXCEPTION_H

#include "BaseException.h"

class NotNullException : public BaseException
{
public:
    NotNullException();
    NotNullException(QString message);
    NotNullException(const char *message);
};

#endif // NOTNULLEXCEPTION_H
