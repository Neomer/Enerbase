#include <QDebug>

#include "StringHelper.h"
#include <QDateTime>

StringHelper::StringHelper() :
    _randomGenerator(static_cast<quint32>(QDateTime::currentSecsSinceEpoch()))
{

}

void StringHelper::StringToConstChar(const QString &data, char *buffer)
{
    auto ba = data.toLatin1();
    strcpy(buffer, ba.constData());
}

void StringHelper::StringToConstChar(const QStringView &data, char *buffer)
{
    auto ba = data.toLatin1();
    strcpy(buffer, ba.constData());
}

i32 StringHelper::StringLength(const QStringView &data)
{
    return data.toLatin1().length();
}

void StringHelper::GetRandomString(QString &data, i16 size)
{
    for (auto i = size; i > 0; )
    {

    }
}
