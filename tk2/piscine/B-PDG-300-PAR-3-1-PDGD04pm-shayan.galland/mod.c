/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include <string.h>
#include "B-PDG-300_d04pm/int_list.h"

int int_list_get_elem_at_front(int_list_t list)
{
    return list ? list->value : 0;
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return 0;
    int_node_t *current = list;
    while (current->next)
        current = current->next;
    return current->value;
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_node_t *temp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    *front_ptr = (*front_ptr)->next;
    free(temp);
    return true;
}

void int_list_clear(int_list_t *front_ptr)
{
    while (*front_ptr)
        int_list_del_elem_at_front(front_ptr);
}

int int_list_get_elem_at_position(int_list_t list , unsigned int position)
{
    int_node_t *current = list;

    if (list == NULL)
        return 0;
    for (unsigned int i = 0; i < position; i++) {
        if (current->next == NULL)
            return 0;
        current = current->next;
    }
    return current->value;
}