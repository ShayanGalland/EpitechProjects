/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"

typedef struct {
    Class base;
    int x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    (void)args;

    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this == NULL)
        raise("Class NULL");
}

static char *Point_str(PointClass *this)
{
    char *res = malloc(sizeof(*this));

    if (res == NULL)
        raise("Malloc failed");
    sprintf(res, "<Point (%d, %d)>", this->x, this->y);
    return (res);
}



// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
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

const Class   *Point = (const Class *)&_description;
