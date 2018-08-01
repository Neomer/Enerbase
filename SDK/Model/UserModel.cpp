#include "UserModel.h"

UserModel::UserModel() :
    AbstractIdentifiedEntity()
{
    registerORMmethods();
}

void UserModel::registerORMmethods()
{
    AbstractIdentifiedEntity::registerORMmethods();

    _metadata.registerMethod("Username", new Event(std::function<void(QString)>(std::bind(&UserModel::setUsername, this, std::placeholders::_1))));
    _metadata.registerMethod("Username", new Event(std::function<QString(void)>(std::bind(&UserModel::getUsername, this))));

    _metadata.registerMethod("Password", new Event(std::function<void(QString)>(std::bind(&UserModel::setPassword, this, std::placeholders::_1))));
    _metadata.registerMethod("Password", new Event(std::function<QString(void)>(std::bind(&UserModel::getPassword, this))));

    _metadata.registerMethod("LastVisit", new Event(std::function<void(QDateTime)>(std::bind(&UserModel::setLastVisit, this, std::placeholders::_1))));
    _metadata.registerMethod("LastVisit", new Event(std::function<QDateTime(void)>(std::bind(&UserModel::getLastVisit, this))));
}
