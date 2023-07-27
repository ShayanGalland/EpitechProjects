/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _STACK_H
    #define _STACK_H
    #include <stdlib.h>
struct stack {
    void **stack;
    int max;
    int count;
};
typedef struct stack stack_t;

stack_t *create_stack(int max);
void stack_realloc(stack_t *stack, int new_size);
void stack_push(stack_t *stack, void *data);
void *stack_pop(stack_t *stack);
int stack_isEmpty(stack_t *stack);

#endif