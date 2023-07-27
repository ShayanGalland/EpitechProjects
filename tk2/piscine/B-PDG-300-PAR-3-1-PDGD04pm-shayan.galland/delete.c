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

bool pos_zero(int position, int_list_t *front_ptr, int_node_t **temp)
{
    if (position == 0) {
        *temp = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        return true;
    } else {
        return false;
    }
}

bool int_list_del_elem_at_position(int_list_t *front_ptr
, unsigned int position)
{
    int_node_t *current = NULL;
    int_node_t *temp = NULL;

    if (*front_ptr == NULL)
        return false;
    if (pos_zero(position, front_ptr, &temp)) {
        free(temp);
        return true;
    }
    current = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (current->next == NULL)
            return false;
        current = current->next;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_node_t *current = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    while (current->next->next)
        current = current->next;
    free(current->next);
    current->next = NULL;
    return true;
}

int pos_none(int_list_t *front_ptr , unsigned int
position, int_node_t *new_node)
{
    if (position == 0) {
        new_node->next = *front_ptr;
        *front_ptr = new_node;
        return 1;
    } else
        return 0;
}

bool int_list_add_elem_at_position(int_list_t *front_ptr
, int elem , unsigned int position)
{
    int_node_t *new_node = malloc(sizeof(int_node_t));
    int_node_t *current = *front_ptr;

    new_node->value = elem;
    if (*front_ptr == NULL && position != 0) {
        free(new_node);
        return false;
    }
    if (pos_none(front_ptr, position, new_node) == 1)
        return true;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            free(new_node);
            return false;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return true;
}
