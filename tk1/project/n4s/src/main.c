/*
** EPITECH PROJECT, 2022
** main
** File description:
** n4s
*/

#include "../include/my.h"

void car_vectors()
{
    char *buffer;
    size_t tmp;
    char **tab;
    float dist;
    float left;
    float right;

    dprintf(1, "GET_INFO_LIDAR\n");
    if (getline(&buffer, &tmp, stdin) == -1)
            return ;
    tab = my_str_to_word_array(buffer, ':');
    left = atof(tab[3]);
    dist = atof(tab[18]);
    right = atof(tab[33]);
    speed(dist);
    getline(&buffer, &tmp, stdin);
    direction(left, right, dist);
    getline(&buffer, &tmp, stdin);
    free_arr(tab);
}

int main(void)
{
    char *buffer;
    size_t tmp;

    dprintf(1, "START_SIMULATION\n");
    if (getline(&buffer, &tmp, stdin) == -1)
            return 84;
    while (1) {
    car_vectors();
    }
    dprintf(1, "CAR_FORWARD:0.0\n");
    dprintf(1, "STOP_SIMULATION\n");
    return 0;
}
