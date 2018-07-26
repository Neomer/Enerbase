#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <QString>
#include <QStringView>
#include <QRandomGenerator>
#include <QDateTime>

#include <SDK/sdk_global.h>
#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>

class SDKSHARED_EXPORT StringHelper
{
    SINGLETON(StringHelper)

public:
    static void StringToConstChar(const QString &data, char *buffer);
    static void StringToConstChar(const QStringView &data, char *buffer);

    static i32 StringLength(const QStringView &data);

    void GetRandomString(QString &data, i16 size);

private:
    QRandomGenerator _randomGenerator;
};

#endif // STRINGHELPER_H
