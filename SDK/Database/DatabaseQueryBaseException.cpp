#include "DatabaseQueryBaseException.h"

DatabaseQueryBaseException::DatabaseQueryBaseException(const AbstractDatabaseProvider *provider, QString message) :
    DatabaseException(provider, message)
{

}
