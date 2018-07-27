#ifndef ENTITYHELPER_H
#define ENTITYHELPER_H

#include <QPair>
#include <QVector>

#include <SDK/Defines.h>
#include <SDK/BasicTypes.h>
#include <SDK/Database/AbstractDatabaseQuery.h>
#include <SDK/Database/AbstractDatabaseProvider.h>
#include <SDK/Model/AbstractEntity.h>
#include <SDK/Model/AbstractIdentifiedEntity.h>

class SDKSHARED_EXPORT EntityHelper
{
    SINGLETON(EntityHelper)

public:
    ///
    /// \brief Load Заполняет значения свойств сущности результатом запроса к БД
    /// \param query (in) результат запроса к БД
    /// \param entity (in) сущность
    ///
    void Load(const AbstractDatabaseQuery *query, AbstractEntity *entity) const;
    ///
    /// \brief GetFields возвращает список свойств, помеченных как STORED
    /// \param entity (in) сущность
    /// \param fields (out) список полей сущности
    /// \param quote (in) обрамляющий символ
    /// \param recursievly (in) проводить поиск по базовым классам
    ///
    void GetFields(const AbstractEntity *entity, QStringList &fields, char quote = 0, bool recursievly = true) const;

    ///
    /// \brief GetProperties возвращает список значений всех пар <имя свойства> = <значение свойства>
    /// \param entity (in) сущность
    /// \param properties (out) список значений
    ///
    void GetProperties(const AbstractEntity *entity, QVector< QPair< QString, QVariant > > &properties);

    void GetById(QUuid id, AbstractIdentifiedEntity *entity, AbstractDatabaseProvider *provider) const;

private:
    void GetFieldsPrivate(const QMetaObject *metaObject, QStringList &fields, char quote = 0, bool recursievly = true) const;
    void GetPropertiesPrivate(const AbstractEntity *entity, const QMetaObject *metaObject, QVector< QPair< QString, QVariant > > &properties);

};

#endif // ENTITYHELPER_H
