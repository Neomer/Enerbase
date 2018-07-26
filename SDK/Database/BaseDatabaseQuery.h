#ifndef BASEDATABASEQUERY_H
#define BASEDATABASEQUERY_H

#include "AbstractDatabaseQuery.h"
#include "BasicTypes.h"
#include "../sdk_global.h"

///
/// \brief The BaseDatabaseQuery class contains main navigation tools, such as next(), last(), first(), prev()
///
class SDKSHARED_EXPORT BaseDatabaseQuery : public AbstractDatabaseQuery
{
public:
    BaseDatabaseQuery();

public:
    i32 getCurrentRow() { return _row_idx; }

    // AbstractDatabaseQuery interface
public:
    virtual bool first() override;
    virtual bool last() override;
    virtual bool next() override;
    virtual bool prev() override;
    virtual bool isEnd() override;

private:
    i32 _row_idx;
};

#endif // BASEDATABASEQUERY_H
