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
                TestEntity ent;
                qDebug() << "Before invoke:" << ent.getId();

                try {
                    ent.metadata().write("Id", QUuid::createUuid());
                    qDebug() << "After invoke:" << ent.getId();
                    auto uid = ent.metadata().read<QUuid>("Id");
                    qDebug() << "Value from metadata:" << uid;
                } catch (NotFoundException &) {
                    qDebug() << "Method not found!";
                }
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
