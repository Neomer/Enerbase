#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <QException>
#include "../sdk_global.h"

class SDKSHARED_EXPORT BaseException : public QException
{
public:
    BaseException();
    BaseException(QString message);
    BaseException(const char *message);

    QString getMessage();

private:
    QString _message;

    // QException interface
public:
    void raise() const override;
    QException *clone() const override;

    // exception interface
public:
    virtual const char* what() const throw()
    {
        return _message.toStdString().c_str();
    }

};

#endif // BASEEXCEPTION_H
