/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "stack.h"

stack_t *create_stack(int max)
{
    stack_t *stack = malloc(sizeof(stack_t));

    stack->stack = malloc(sizeof(void*)*max);
    stack->max = max;
    stack->count = 0;
    return stack;
}

void stack_realloc(stack_t *stack, int new_size)
{
    void **new_stack = malloc(sizeof(void*)*new_size);
    for (int i = 0; i < stack->max; i++)
        new_stack[i] = stack->stack[i];
    free(stack->stack);
    stack->stack = new_stack;
    stack->max = new_size;
}

void stack_push(stack_t *stack, void *data)
{
    if (stack->count + 1 >= stack->max)
        stack_realloc(stack,stack->max*2);
    stack->stack[stack->count] = data;
    stack->count++;
}

void *stack_pop(stack_t *stack)
{
    void *data = stack->stack[0];
    for (int i = 1; i < stack->count; i++)
        stack->stack[i-1] = stack->stack[i];
    stack->count--;
    return data;
}

int stack_isEmpty(stack_t *stack)
{
    if (stack->count > 0)
        return 0;
    else
        return 1;
};
