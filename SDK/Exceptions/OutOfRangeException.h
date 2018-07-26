#ifndef OUTOFRANGEEXCEPTION_H
#define OUTOFRANGEEXCEPTION_H

#include "BaseException.h"
#include "../sdk_global.h"

class SDKSHARED_EXPORT OutOfRangeException : public BaseException
{
public:
    OutOfRangeException();
    OutOfRangeException(QString message);
    OutOfRangeException(const char *message);
};

#endif // OUTOFRANGEEXCEPTION_H
