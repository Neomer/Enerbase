#include <QString>
#include <QtTest>

class SDK_TestsTest : public QObject
{
    Q_OBJECT

public:
    SDK_TestsTest();

private Q_SLOTS:


};

SDK_TestsTest::SDK_TestsTest()
{
}


QTEST_APPLESS_MAIN(SDK_TestsTest)

#include "tst_SDK_TestsTest.moc"
