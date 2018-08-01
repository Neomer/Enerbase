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

            UserModel usr;

            try
            {
                usr.getById(QUuid("0ce63551-bab7-4394-b8f7-f282262f6437"));
            }
            catch (NotNullException &)
            {

            }
            catch (NotFoundException &)
            {

            }

            qDebug() << usr.metadata().read<QString>("Username");
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
