/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "int.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL)
        raise("Class must be allocated");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static IntClass *int_add(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (IntClass *)new(Int, this->x + other->x, this->y + other->y);
}

static IntClass *int_sub(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (IntClass *)new(Int, this->x - other->x, this->y - other->y);
}

static IntClass *int_mul(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (IntClass *)new(Int, this->x * other->x, this->y * other->y);
}

static IntClass *int_div(IntClass *this, IntClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    if (other->x == 0 || other->y == 0)
        raise("division by zero detected, please don't");
    return (IntClass *)new(Int, this->x / other->x, this->y / other->y);
}

static char *to_string2(IntClass *this)
{
    char *str = NULL;

    asprintf(&str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&to_string2,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mul,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Int = (const Class *)&_description;