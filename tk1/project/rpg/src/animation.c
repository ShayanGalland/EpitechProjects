/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void create_and_anim_hero(game_t *game)
{
    sfIntRect rect;

    if (game->game_time > game->hero.frame_hero) {
        game->hero.anim_hero += 1;
        if (game->hero.anim_hero == 9)
            game->hero.anim_hero = 1;
        game->hero.frame_hero += 0.10f;
    }
    if (game->hero.no_anim == 1)
        rect.left = 64 * game->hero.anim_hero;
    else if (game->hero.side == 127 || game->hero.side == 0)
        rect.left = 64*5;
    else
        rect.left = 0;
    rect.top = 0 + game->hero.side;
    rect.height = 53;
    rect.width = 37;
    sfSprite_setTextureRect(game->hero.hero, rect);
}

void create_and_anim_pnj(game_t *game)
{
    sfIntRect rect;

    if (game->game_time > game->pnj.frame) {
        game->pnj.anim += 1;
        if (game->pnj.anim == 4)
            game->pnj.anim = 1;
        game->pnj.frame += 0.10f;
    }
    rect.left = 1280*game->pnj.anim;
    rect.top = 0;
    rect.height = 1440;
    rect.width = 1280;
    sfSprite_setTextureRect(game->pnj.pnj, rect);
}

void create_and_anim_boom(game_t *game)
{
    sfIntRect rect;

    sfSprite_setScale(game->hero.shoot.boom, start_point(0.5f, 0.5f));
    if (game->game_time > game->hero.shoot.frame) {
        game->hero.shoot.animx += 1;
        if (game->hero.shoot.animx == 8) {
            game->hero.shoot.animx = 1;
            game->hero.shoot.animy += 1;
        }
        if (game->hero.shoot.animy == 6) {
            game->hero.shoot.animy = 1;
        game->hero.shoot.frame += 0.03f;
        game->hero.shoot.is_boom = 0;
        }
    }
    rect.left = 256*game->hero.shoot.animx;
    rect.top = 256*(game->hero.shoot.animy-1);
    rect.height = 256;
    rect.width = 256;
    sfSprite_setTextureRect(game->hero.shoot.boom, rect);
}