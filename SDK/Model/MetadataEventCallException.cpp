#include "MetadataEventCallException.h"

MetadataEventCallException::MetadataEventCallException() :
    BaseException ()
{

}

MetadataEventCallException::MetadataEventCallException(QString message) :
    BaseException (message)
{

}

MetadataEventCallException::MetadataEventCallException(const char *message) :
    BaseException (message)
{

}
