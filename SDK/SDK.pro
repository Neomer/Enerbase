#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T09:10:06
#
#-------------------------------------------------

QT       -= gui

TARGET = SDK
TEMPLATE = lib

DEFINES += SDK_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database/AbstractDatabaseModel.cpp \
    Database/AbstractDatabaseQuery.cpp \
    Database/AbstractDatabaseProvider.cpp \
    Exceptions/BaseException.cpp \
    Database/DatabaseException.cpp \
    Helpers/StringHelper.cpp \
    Database/DatabaseConnectionRefusedException.cpp \
    Helpers/DatabaseHelper.cpp \
    Exceptions/EmptyListReadException.cpp \
    Exceptions/NotNullException.cpp \
    Database/DatabaseQueryBaseException.cpp \
    Database/BaseDatabaseQuery.cpp \
    Exceptions/OutOfRangeException.cpp \
    Exceptions/DataFormatException.cpp \
    Model/AbstractEntity.cpp \
    Helpers/EntityHelper.cpp \
    Model/EntityBaseException.cpp \
    Model/PropertyReadWriteException.cpp \
    Model/AbstractIdentifiedEntity.cpp \
    Exceptions/NotFoundException.cpp \
    Database/AbstractDatabaseFormatter.cpp \
    Database/DefaultDatabaseFormatter.cpp \
    Model/UserModel.cpp \
    Model/ObjectsTreeModel.cpp \
    Managers/ObjectsTreeManager.cpp \
    Database/DuplicateException.cpp

HEADERS += \
        sdk_global.h \ 
    Database/AbstractDatabaseModel.h \
    Serialization/IJsonSerializable.h \
    Defines.h \
    Database/AbstractDatabaseQuery.h \
    Database/AbstractDatabaseProvider.h \
    Exceptions/BaseException.h \
    Database/DatabaseException.h \
    Helpers/StringHelper.h \
    BasicTypes.h \
    Database/DatabaseConnectionRefusedException.h \
    Database/AbstractConnectionStringProvider.h \
    Helpers/DatabaseHelper.h \
    Exceptions/EmptyListReadException.h \
    Exceptions/NotNullException.h \
    Database/DatabaseQueryBaseException.h \
    Database/BaseDatabaseQuery.h \
    Exceptions/OutOfRangeException.h \
    Exceptions/DataFormatException.h \
    Model/AbstractEntity.h \
    Helpers/EntityHelper.h \
    Model/EntityBaseException.h \
    Model/PropertyReadWriteException.h \
    Model/AbstractIdentifiedEntity.h \
    Exceptions/NotFoundException.h \
    Database/AbstractDatabaseFormatter.h \
    Database/DefaultDatabaseFormatter.h \
    Model/UserModel.h \
    Model/ObjectsTreeModel.h \
    Managers/ObjectsTreeManager.h \
    Database/DuplicateException.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../paths.pri)
include(../modules.pri)
