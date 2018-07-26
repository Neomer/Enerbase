#ifndef DATAFORMATEXCEPTION_H
#define DATAFORMATEXCEPTION_H

#include "BaseException.h"
#include "../sdk_global.h"

class SDKSHARED_EXPORT DataFormatException : public BaseException
{
public:
    DataFormatException();
    DataFormatException(QString message);
    DataFormatException(const char *message);
};

#endif // DATAFORMATEXCEPTION_H
