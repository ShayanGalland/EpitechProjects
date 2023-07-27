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

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

bool int_list_is_empty(int_list_t list)
{
    return list == NULL;
}

void int_list_dump(int_list_t list)
{
    int_node_t *current = list;

    while (current) {
    printf("%d\n", current->value);
    current = current->next;
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr , int elem)
{
    int_node_t *new_node = malloc(sizeof(int_node_t));

    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr , int elem)
{
    int_node_t *new_node = malloc(sizeof(int_node_t));
    int_node_t *current = *front_ptr;

    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return true;
    }
    while (current->next)
        current = current->next;
    current->next = new_node;
    return true;
}
