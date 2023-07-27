/*
** EPITECH PROJECT, 2022
** display_file
** File description:
** display_file
*/

#include "necessary.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

int find_letter(char *str, char c, int n)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && n == 0)
            return (i);
        if (str[i] == c)
            n--;
    }
    return (-1);
}

int count_back(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}

char *my_star(char *star, int len)
{
    for (int i = 1; i < len;i++)
        star[i] = '*';
    return (star);
}

int win(char *str, int len, int lose)
{
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '*' || str[i] == '?')
            count++;
    }
    if (lose == my_strlen(str) + 1) {
        my_putstr("\n\n");
        my_putstr("You lost!\n");
        return 1;
    }
    if (count == 0) {
        my_putstr("\n\n");
        my_putstr("Congratulations!\n");
        return 1;
    }
    else
        return 0;
}

void display_file(char *buff)
{
    char *path = load_file_in_mem(buff);
    char **tab = my_str_to_word_array(path);
    char *my_string = NULL;
    size_t my_size = 0;
    int numbers = generate_random_number(0, count_back(path)-1);
    int len = my_strlen(tab[numbers]);
    char *star = malloc(sizeof(char) * (len + 1));
    int tries = 1;

    display_init(tab, numbers, tries, star);
    while (getline(&my_string, &my_size, stdin) != -1) {
        tries++;
        display_incond(tab, star, my_string, numbers);
        if (win(star, len, tries))
            break;
        star = my_star(star, my_strlen(star));
        star[0] = tab[numbers][0];
        end_disp(tries);
    }
    free(star);
    my_free(tab);
}
