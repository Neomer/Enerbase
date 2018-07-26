#include "BaseDatabaseQuery.h"

BaseDatabaseQuery::BaseDatabaseQuery() :
    _row_idx(0)
{

}

bool BaseDatabaseQuery::first()
{
    _row_idx = 0;
    return !isEmpty();
}

bool BaseDatabaseQuery::last()
{
    if (!isEmpty())
    {
        _row_idx = rowCount() - 1;
        return true;
    }
    return false;
}

bool BaseDatabaseQuery::next()
{
    _row_idx++;
    return isEnd();
}

bool BaseDatabaseQuery::prev()
{
    if (_row_idx > 0)
    {
        _row_idx--;
        return true;
    }
    return false;
}

bool BaseDatabaseQuery::isEnd()
{
    return (isEmpty() || _row_idx >= rowCount());
}
