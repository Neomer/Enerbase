#include "MainWindow.h"
#include <QDebug>
#include <QApplication>

#include <DatabaseProviders/PostgreSQLProvider/PostgreSQLProvider.h>
#include <DatabaseProviders/PostgreSQLProvider/PostgreSQLConnectionStringProvider.h>
#include <SDK/Helpers/DatabaseHelper.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
    }
    catch (NotNullException &)
    {

    }


    MainWindow w;
    w.show();

    auto result = a.exec();

    DatabaseHelper::Instance().unregisterAll();
}
