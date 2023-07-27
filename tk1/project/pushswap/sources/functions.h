/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

struct list{
    int* l;
    int size;
};
typedef struct list list;

void sort_a_list(list *copy,list *copy2, int last);
int find_smaller(list *l_a, int last);
void bubble_sort_swap_left(int rot_left, list *l_a);
void sort_a(list *l_a, list *l_b, int i, int number_to_find);
void sort_a_bis(list *l_a, list *l_b, int rot_left);
int my_putnbr(int nb);
void my_putchar(char c);
list *create_list_struct(int size);
list *free_list_struct(list *l_a);
int my_getnbr(char const *str);
void swap(list *swap);
int push(list *l_a, list *l_b);
void rotate(list* l_a);
void rrotate(list* l_a);
int is_sorted(list* l_a);
void replace_numbers(list* l_a);
void bubble_sort(list *l_a, list *l_b);
void push_sort(list *l_a, list* l_b);
void pop_sort(list *l_a, list* l_b);
void sort_numbers (list* l_a, list* l_b);
void my_putstr(char const *str);


#endif
