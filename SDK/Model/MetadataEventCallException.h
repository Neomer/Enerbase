#ifndef METADATAEVENTCALLEXCEPTION_H
#define METADATAEVENTCALLEXCEPTION_H

#include <SDK/Exceptions/BaseException.h>

class SDKSHARED_EXPORT MetadataEventCallException : public BaseException
{
public:
    MetadataEventCallException();
    MetadataEventCallException(QString message);
    MetadataEventCallException(const char *message);
};

#endif // METADATAEVENTCALLEXCEPTION_H
