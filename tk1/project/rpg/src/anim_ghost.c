/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void create_and_anim_ghost1(game_t *game, int i)
{
    sfIntRect rect;

    if (game->game_time > game->ghost[0][i].frame) {
        game->ghost[0][i].anim += 1;
        if (game->ghost[0][i].anim == 5)
            game->ghost[0][i].anim = 1;
        game->ghost[0][i].frame += 0.10f;
    }
    rect.left = 169 * game->ghost[0][i].anim;
    rect.top = 0;
    rect.height = 330 / 2;
    rect.width = 175;
    sfSprite_setTextureRect(game->ghost[0][i].ghost, rect);
}

void create_and_anim_ghost2(game_t *game, int i)
{
    sfIntRect rect;

    if (game->game_time > game->ghost[1][i].frame) {
        game->ghost[1][i].anim += 1;
        if (game->ghost[1][i].anim == 12)
            game->ghost[1][i].anim = 1;
        game->ghost[1][i].frame += 0.10f;
    }
    rect.left = 156 * game->ghost[1][i].anim;
    rect.top = 0;
    rect.height = 130;
    rect.width = 160;
    sfSprite_setTextureRect(game->ghost[1][i].ghost, rect);
}

void create_and_anim_ghost3(game_t *game, int i)
{
    sfIntRect rect;

    if (game->game_time > game->ghost[2][i].frame) {
        game->ghost[2][i].anim += 1;
        if (game->ghost[2][i].anim == 12)
            game->ghost[2][i].anim = 1;
        game->ghost[2][i].frame += 0.10f;
    }
    rect.left = 296 * game->ghost[2][i].anim;
    rect.top = 0;
    rect.height = 350;
    rect.width = 305;
    sfSprite_setTextureRect(game->ghost[2][i].ghost, rect);
}