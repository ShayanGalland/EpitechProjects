/*
** EPITECH PROJECT, 2022
** display_start
** File description:
** display_start
*/

#include "necessary.h"

void display_start(void)
{
    my_putstr("*: invalid letter\n");
    my_putstr("?: incorrectly placed letter\n");
    my_putstr("Will you find the secret word ?\n");
}

int display_word(char *my_string, char *tab)
{
    int len = my_strlen(my_string + 1);
    int count_tab = my_strlen(tab);

    if (len < count_tab)
        return (1);
    
    if (len > count_tab)
        return (2);
    return (1);
}

void display_init(char **tab, int numbers, int tries, char *star)
{
    int len = my_strlen(tab[numbers]);

    display_start(); 
    star = my_star(star, len);
    star[0] = tab[numbers][0];
    init_displ(star, tries);
}

void display_incond(char **tab, char *star, char *my_string, int numbers)
{
    extend_dis(my_string, tab, star, numbers);
    my_putstr(star);
}
