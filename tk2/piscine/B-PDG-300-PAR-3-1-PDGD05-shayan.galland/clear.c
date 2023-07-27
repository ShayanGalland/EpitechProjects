/*
** EPITECH PROJECT, 2023
** the .c file
** File description:
** project c file
*/

#include "string.h"

void clear(string_t *this)
{
    this->assign_c(this, "\0");
}
