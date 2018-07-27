#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H

#include "BaseException.h"
#include "../sdk_global.h"

class SDKSHARED_EXPORT NotFoundException : public BaseException
{
public:
    NotFoundException();
    NotFoundException(QString message);
    NotFoundException(const char *message);
};

#endif // NOTFOUNDEXCEPTION_H
