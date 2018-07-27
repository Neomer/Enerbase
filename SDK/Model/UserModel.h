#ifndef USERMODEL_H
#define USERMODEL_H

#include <QDateTime>

#include <SDK/Model/AbstractIdentifiedEntity.h>

class SDKSHARED_EXPORT UserModel : public AbstractIdentifiedEntity
{
    Q_OBJECT

    Q_PROPERTY(QString Username READ getUsername WRITE setUsername NOTIFY UsernameChanged STORED true)
    Q_PROPERTY(QString Password READ getPassword WRITE setPassword NOTIFY PasswordChanged STORED true)
    Q_PROPERTY(QDateTime LastVisit READ getLastVisit WRITE setLastVisit NOTIFY LastVisitChanged STORED true)

    QDateTime m_LastVisit;
    QString m_Password;
    QString m_Username;

public:
    UserModel();

    // AbstractEntity interface
public:
    virtual const char *getTableName() const override { return "Users"; }
    QDateTime getLastVisit() const
    {
        return m_LastVisit;
    }
    QString getPassword() const
    {
        return m_Password;
    }

    QString getUsername() const
    {
        return m_Username;
    }

public slots:
    void setLastVisit(QDateTime LastVisit)
    {
        if (m_LastVisit == LastVisit)
            return;

        m_LastVisit = LastVisit;
        emit LastVisitChanged(m_LastVisit);
    }
    void setPassword(QString Password)
    {
        if (m_Password == Password)
            return;

        m_Password = Password;
        emit PasswordChanged(m_Password);
    }

    void setUsername(QString Username)
    {
        if (m_Username == Username)
            return;

        m_Username = Username;
        emit UsernameChanged(m_Username);
    }

signals:
    void LastVisitChanged(QDateTime LastVisit);
    void PasswordChanged(QString Password);
    void UsernameChanged(QString Username);
};

#endif // USERMODEL_H
