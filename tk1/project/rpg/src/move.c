/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

static void move_side(game_t *game, sfSprite *map, float speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfSprite_move(map, start_point
        (speed*game->hero.mv_q*game->hero.ms_q, 0));
        game->hero.side = 63;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sfSprite_move(map, start_point
        (-speed*game->hero.mv_d*game->hero.ms_d, 0));
        game->hero.side = 190;
    }
}

float init_speed(game_t *game)
{
    if (game->map_select == 1 && game->other_world == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
        game->hero.mana_regen == 0)
            return 1.1f;
        else
            return 0.5f;
    }
    if (game->map_select == 2 || game->other_world == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
        game->hero.mana_regen == 0)
            return 3.4f;
        else
            return 2.2f;
    }
    return 0;
}

void move_player(game_t *game, sfSprite *map)
{
    float s = init_speed(game);

    if (sfKeyboard_isKeyPressed(sfKeyLShift) && game->hero.mana_regen == 0) {
        s = init_speed(game);
        if (game->game_time > game->hero.delay_mana) {
            game->hero.less_mana -= 0.0004f;
            game->hero.delay_mana += 0.01f;
        }
    } else if (game->game_time > game->hero.delay_mana)
            game->hero.delay_mana += 0.01f;
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sfSprite_move(map, start_point
        (0, -s*game->hero.mv_s*game->hero.ms_s));
        game->hero.side = 127;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sfSprite_move(map, start_point(0, s*game->hero.mv_z*game->hero.ms_z));
        game->hero.side = 0;
    }
    move_side(game, map, s);
}

void no_anim(game_t *game)
{
    int count = 0;

    if (!sfKeyboard_isKeyPressed(sfKeyS))
        count++;
    if (!sfKeyboard_isKeyPressed(sfKeyQ))
        count++;
    if (!sfKeyboard_isKeyPressed(sfKeyD))
        count++;
    if (!sfKeyboard_isKeyPressed(sfKeyZ))
        count++;
    if (count == 4)
        game->hero.no_anim = 0;
    else
        game->hero.no_anim = 1;
}