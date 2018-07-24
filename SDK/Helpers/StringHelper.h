#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <QString>
#include <QStringView>
#include <QRandomGenerator>

#include <SDK/sdk_global.h>
#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>

class SDKSHARED_EXPORT StringHelper
{
    SINGLETON(StringHelper)

public:
    static const char *StringToConstChar(const QStringView &data);
    static void GetRandomString(QString &data, i16 size);

private:
    QRandomGenerator _randomGenerator;
};

#endif // STRINGHELPER_H
