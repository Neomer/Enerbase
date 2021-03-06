#ifndef TESTENTITY_H
#define TESTENTITY_H

#include <QUuid>
#include <QDateTime>

#include <SDK/BasicTypes.h>
#include <SDK/Model/AbstractIdentifiedEntity.h>

class TestEntity : public AbstractIdentifiedEntity
{
    Q_OBJECT

    Q_PROPERTY(QString Name READ getName WRITE setName NOTIFY NameChanged STORED true )
    Q_PROPERTY(int Index READ getIndex WRITE setIndex NOTIFY IndexChanged STORED true)
    Q_PROPERTY(QDateTime date READ getDate WRITE setDate NOTIFY DateChanged STORED true)
    Q_PROPERTY(bool logical READ getLogical WRITE setLogical NOTIFY LogicalChanged STORED true)

    QString m_Name;
    int m_Index;
    QDateTime m_date;
    bool m_logical;

public:
    TestEntity();

    QString getName() const
    {
        return m_Name;
    }

    int getIndex() const
    {
        return m_Index;
    }

    QDateTime getDate() const
    {
        return m_date;
    }

    bool getLogical() const
    {
        return m_logical;
    }

public slots:
    void setName(QString Name)
    {
        if (m_Name == Name)
            return;

        m_Name = Name;
        emit NameChanged(m_Name);
    }

    void setIndex(int Index)
    {
        if (m_Index == Index)
            return;

        m_Index = Index;
        emit IndexChanged(m_Index);
    }

    void setDate(QDateTime date)
    {
        if (m_date == date)
            return;

        m_date = date;
        emit DateChanged(m_date);
    }

    void setLogical(bool logical)
    {
        if (m_logical == logical)
            return;

        m_logical = logical;
        emit LogicalChanged(m_logical);
    }

signals:
    void NameChanged(QString Name);
    void IndexChanged(int Index);
    void DateChanged(QDateTime date);
    void LogicalChanged(bool logical);

    // AbstractEntity interface
public:
    virtual const char *getTableName() const override { return "Test"; }
};

#endif // TESTENTITY_H
