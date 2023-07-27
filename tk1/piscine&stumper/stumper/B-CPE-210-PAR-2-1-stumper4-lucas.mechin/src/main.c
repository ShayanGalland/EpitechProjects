/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "necessary.h"

int main(int ac, char **av)
{
    game_t game;

    count_block("pokecfg", &game);
    for (int i = 0; i != game.nb_block; i++) {
        for (int j = 0; j != game.block[i].piece.dim.y+1; j++)
            printf("%s\n",game.block[i].piece.tab[j]);
    }
    return (0);
}
