/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "float.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL)
        raise("Class must be allocated");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static FloatClass *float_add(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (FloatClass *)new(Float, this->x + other->x, this->y + other->y);
}

static FloatClass *float_sub(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (FloatClass *)new(Float, this->x - other->x, this->y - other->y);
}

static FloatClass *float_mul(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (FloatClass *)new(Float, this->x * other->x, this->y * other->y);
}

static FloatClass *float_div(FloatClass *this, FloatClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    if (other->x == 0 || other->y == 0)
        raise("division by zero detected, please don't");
    return (FloatClass *)new(Float, this->x / other->x, this->y / other->y);
}

static char *to_string2(FloatClass *this)
{
    char *str = NULL;

    asprintf(&str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&to_string2,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Float = (const Class *)&_description;