/*
** EPITECH PROJECT, 2021
** tools
** File description:
** main
*/

#include "my.h"

void delay(int del)
{
    clock_t start = clock();
    clock_t end = start + del*CLOCKS_PER_SEC/1000;
    while (end > clock());

}

void map_mid(int j, int i, game_t *game)
{
    if (game->map2.tab[j][i] != ' ')
        printw("%c", game->map2.tab[j][i]);
    else
        printw("%c", game->map.tab[j][i]);
}

void level(game_t *game)
{
    if (game->score % 5)
        game->level++;
}

void prt_map(game_t *game)
{
    for (int j = 0; j < 40; j++) {
        if (j == 2 && game->score < 10)
            printw("score : %d       ", game->score);
        else if (j == 2 && game->score >= 10)
            printw("score : %d      ", game->score);
        else if (j == 4 && game->level < 10)
            printw("level : %d       ", game->level);
        else if (j == 4 && game->level >= 10)
            printw("score : %d      ", game->level);
        else
            printw("                ");
        for (int i = 0; i < 15; i++)
            map_mid(j, i, game);
        printw("\n");
    }
}