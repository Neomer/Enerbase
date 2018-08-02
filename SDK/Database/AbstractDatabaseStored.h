#ifndef ABSTRACTDATABASESTORED_H
#define ABSTRACTDATABASESTORED_H

#include <vector>

#include "AbstractDatabaseQuery.h"

class AbstractDatabaseStored
{
public:
    virtual ~AbstractDatabaseStored();

    virtual void fromDatabaseQuery(const AbstractDatabaseQuery *query) = 0;
    virtual const char * getTableName() = 0;
    virtual void getParameters(std::vector<const char *, const char *> &params) = 0;
};

#endif // ABSTRACTDATABASESTORED_H
