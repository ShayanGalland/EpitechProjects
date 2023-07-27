/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include "vertex.h"
#include "new.h"
#include <stdio.h>

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void vertex_ctor(VertexClass *this, va_list *arg)
{
    this->x = va_arg(*arg, int);
    this->y = va_arg(*arg, int);
    this->z = va_arg(*arg, int);
}

static VertexClass *vertex_add(VertexClass *this, VertexClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (VertexClass *)new(Vertex, this->x + other->x, this->y + other->y, this->z + other->z);
}

static VertexClass *vertex_sub(VertexClass *this, VertexClass *other)
{
    if (!this || !other)
        raise("Params must be allocated");
    return (VertexClass *)new(Vertex, this->x - other->x, this->y - other->y, this->z - other->z);
}

static char *to_string(VertexClass *this)
{
    char *str = NULL;

    asprintf(&str, "<%s (%d, %d, %d)>", this->base.__name__, this->x, this->y, this->z);

    return str;
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&to_string,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Vertex = (const Class *)&_description;