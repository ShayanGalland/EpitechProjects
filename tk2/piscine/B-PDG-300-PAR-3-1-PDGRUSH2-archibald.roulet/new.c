#include "raise.h"
#include "new.h"
#include "object.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj;

    if (class == NULL)
        raise("Class is NULL");
    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj;

    if (class == NULL)
        raise("Class is NULL");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Malloc failed");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *ptr)
{
    Class *class = ptr;

    if (ptr == NULL)
        raise("Object is NULL");
    if (class->__dtor__ != NULL)
        class->__dtor__(ptr);
    free(ptr);
}
