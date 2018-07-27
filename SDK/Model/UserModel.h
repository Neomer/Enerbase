#ifndef USERMODEL_H
#define USERMODEL_H

#include <SDK/Model/AbstractIdentifiedEntity.h>

class SDKSHARED_EXPORT UserModel : public AbstractIdentifiedEntity
{
    Q_OBJECT

public:
    UserModel();

    // AbstractEntity interface
public:
    virtual const char *getTableName() const override { return "Users"; }
};

#endif // USERMODEL_H
