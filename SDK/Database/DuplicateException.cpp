#include "DuplicateException.h"

DuplicateException::DuplicateException(const AbstractDatabaseProvider *provider, QString message) :
    DatabaseException(provider, message)
{

}
