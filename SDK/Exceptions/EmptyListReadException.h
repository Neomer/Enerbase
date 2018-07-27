#ifndef EMPTYLISTREADEXCEPTION_H
#define EMPTYLISTREADEXCEPTION_H

#include "BaseException.h"
#include "../sdk_global.h"

class SDKSHARED_EXPORT EmptyListReadException : public BaseException
{
public:
    EmptyListReadException();
    EmptyListReadException(QString message);
    EmptyListReadException(const char *message);
};

#endif // EMPTYLISTREADEXCEPTION_H
