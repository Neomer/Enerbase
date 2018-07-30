#include <QDebug>

#include "StringHelper.h"
#include <QDateTime>

StringHelper::StringHelper() :
    _randomGenerator(static_cast<quint32>(QDateTime::currentSecsSinceEpoch()))
{

}

StringHelper &StringHelper::Instance()
{
    static StringHelper inst;
    return inst;
}

void StringHelper::StringToConstChar(const QString &data, char *buffer)
{
    auto ba = data.toUtf8();
    strcpy(buffer, ba.constData());
}

void StringHelper::StringToConstChar(const QStringView &data, char *buffer)
{
    auto ba = data.toUtf8();
    strcpy(buffer, ba.constData());
}

ui32 StringHelper::StringLength(const QStringView &data)
{
    return data.toUtf8().length();
}

void StringHelper::GetRandomString(QString &data, i16 size)
{
    for (auto i = size; i > 0; )
    {

    }
}
