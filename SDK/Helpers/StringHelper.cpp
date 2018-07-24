#include "StringHelper.h"
#include <QDateTime>

StringHelper::StringHelper() :
    _randomGenerator(static_cast<quint32>(QDateTime::currentSecsSinceEpoch()))
{

}

const char *StringHelper::StringToConstChar(const QStringView &data)
{
    return data.toLatin1().constData();
}

void StringHelper::GetRandomString(QString &data, i16 size)
{
    for (auto i = size; i > 0; )
    {

    }
}
