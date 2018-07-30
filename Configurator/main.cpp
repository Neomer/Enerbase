#include "MainWindow.h"
#include <QDebug>
#include <QApplication>

#include <DatabaseProviders/PostgreSQLProvider/PostgreSQLProvider.h>
#include <DatabaseProviders/PostgreSQLProvider/PostgreSQLConnectionStringProvider.h>
#include <SDK/Helpers/DatabaseHelper.h>
#include <SDK/Helpers/EntityHelper.h>

#include <SDK/Model/PropertyReadWriteException.h>

#include <SDK/Exceptions/OutOfRangeException.h>
#include <SDK/Exceptions/NotFoundException.h>

#include <SDK/Model/UserModel.h>
#include <SDK/Model/ObjectsTreeModel.h>

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
                    ent.getById(QUuid("{0ce63551-bab7-4394-b8f7-f282262f6437}"));
                }
                catch (NotFoundException &ex)
                {
                    qDebug() << "Entity not found!";
                }
                catch (PropertyReadWriteException &ex)
                {
                    qDebug() << "Property write exception:" << ex.getPropertyName();
                }
                query->close();

                ent.setIndex(-2);
                ent.setName("New name");
                ent.save(DatabaseHelper::Instance().getActiveProviderNotNull());

                UserModel user;
                user.getById("{0ce63551-bab7-4394-b8f7-f282262f6437}");
                user.setUsername("admin");
                user.setPassword("admin");
                user.setLastVisit(QDateTime::currentDateTime());
                user.save(DatabaseHelper::Instance().getActiveProviderNotNull());

                ObjectsTreeModel root_node(QUuid::createUuid(), "Корневой элемент");
                root_node.save();
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

        return result;
    }
    catch (BaseException &ex)
    {
        printf("Exception: %s", ex.what());
        return -1;
    }

    return 0;
}
