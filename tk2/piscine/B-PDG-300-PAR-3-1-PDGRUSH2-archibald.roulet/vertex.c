/*
** EPITECH PROJECT, 202
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include <stdlib.h>

typedef struct {
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    (void)args;

    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this == NULL)
        raise("Class NULL");
}

static char *Vertex_str(VertexClass *this)
{
    char *res = malloc(sizeof(*this));

    sprintf(res, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    res[99] = '\0';
    return (res);
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = NULL,    /* Implement this method for exercice 03 */
        .__sub__ = NULL,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Vertex = (const Class *)&_description;
