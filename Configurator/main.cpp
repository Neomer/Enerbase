#include "MainWindow.h"
#include <QDebug>
#include <QApplication>

#include <DatabaseProviders/PostgreSQLProvider/PostgreSQLProvider.h>
#include <DatabaseProviders/PostgreSQLProvider/PostgreSQLConnectionStringProvider.h>
#include <SDK/Helpers/DatabaseHelper.h>
#include <SDK/Exceptions/OutOfRangeException.h>
#include <SDK/Helpers/EntityHelper.h>
#include <SDK/Model/PropertyReadWriteException.h>

#include "TestEntity.h"

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);

        try
        {
            PostgreSQLConnectionStringProvider cs;
            cs.setHost("127.0.0.1");
            cs.setPort(5432);
            cs.setUsername("postgres");
            cs.setPassword("123456");
            cs.setDatabase("Enerbase");
            auto p = new PostgreSQLProvider();
            {
                DatabaseHelper &dbi = DatabaseHelper::Instance();
            }
            try
            {
                p->open(cs);
                DatabaseHelper::Instance().registerProvider(p);
            }
            catch (DatabaseConnectionRefusedException &ex)
            {
                qDebug() << "Database connection refused!" << ex.what();
                delete p;
            }

            try
            {
                auto provider = DatabaseHelper::Instance().getActiveProviderNotNull();
                auto query = provider->exec("select * from \"Enerbase\".\"Test\";");
                qDebug() << "Rows:" << query->rowCount();

                QStringList flist;
                query->fields(flist);
                qDebug() << flist;

                TestEntity ent;

                try
                {
                    ent.getById(QUuid("{0ce63551-bab7-4394-b8f7-f282262f6437}"), DatabaseHelper::Instance().getActiveProviderNotNull());
                }
                catch (PropertyReadWriteException &ex)
                {
                    qDebug() << "Property write exception:" << ex.getPropertyName();
                }
                query->close();
            }
            catch (NotNullException &)
            {

            }
        }
        catch (DatabaseException &ex)
        {
            qDebug() << "Database exception!" << ex.what();
        }

        MainWindow w;
        w.show();

        auto result = a.exec();

        DatabaseHelper::Instance().unregisterAll();
    }
    catch (BaseException &ex)
    {
        printf("Exception: %s", ex.what());
        return -1;
    }
}
