#include "DatabaseException.h"

DatabaseException::DatabaseException(const AbstractDatabaseProvider *provider, QString message) :
    BaseException(message),
    _provider(provider)
{

}
