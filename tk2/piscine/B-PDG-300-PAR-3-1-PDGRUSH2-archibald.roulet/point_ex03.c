/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "point.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL)
        raise("Class must be allocated");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static PointClass *point_add(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (PointClass *)new(Point, this->x + other->x, this->y + other->y);
}

static PointClass *point_sub(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (PointClass *)new(Point, this->x - other->x, this->y - other->y);
}

static PointClass *point_mul(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (PointClass *)new(Point, this->x * other->x, this->y - other->y);
}

static PointClass *point_div(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    if (other->x == 0)
        raise("division by zero detected, reactor meltdown imminent");
    return (PointClass *)new(Point, this->x / other->x, this->y - other->y);
}

static char *to_string2(PointClass *this)
{
    char *str = NULL;

    asprintf(&str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&to_string2,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = (binary_operator_t)&point_mul,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;