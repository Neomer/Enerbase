#ifndef DUPLICATEEXCEPTION_H
#define DUPLICATEEXCEPTION_H

#include "DatabaseException.h"

class SDKSHARED_EXPORT DuplicateException : public DatabaseException
{
public:
    DuplicateException(const AbstractDatabaseProvider *provider, QString message);
};

#endif // DUPLICATEEXCEPTION_H
