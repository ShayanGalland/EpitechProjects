/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "char.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL)
        raise("Class must be allocated");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static CharClass *char_add(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (CharClass *)new(Char, this->x + other->x, this->y + other->y);
}

static CharClass *char_sub(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (CharClass *)new(Char, this->x - other->x, this->y - other->y);
}

static CharClass *char_mul(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (CharClass *)new(Char, this->x * other->x, this->y * other->y);
}

static CharClass *char_div(CharClass *this, CharClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    if (other->x == 0 || other->y == 0)
        raise("division by zero detected, please don't");
    return (CharClass *)new(Char, this->x / other->x, this->y / other->y);
}

static char *to_string2(CharClass *this)
{
    char *str = NULL;

    asprintf(&str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&to_string2,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Char = (const Class *)&_description;