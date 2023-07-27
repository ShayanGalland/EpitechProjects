/*
** EPITECH PROJECT, 2022
** getdata
** File description:
** getdata
*/

#include "include.h"

void kill_ghost(game_t *game)
{
    sfFloatRect ghost;
    sfVector2f bulet = start_point(sfSprite_getPosition
    (game->hero.shoot.ball).x, sfSprite_getPosition(game->hero.shoot.ball).y);

    for (int i = 0; i < MAX_FANTOME_1; i++) {
        ghost = sfSprite_getGlobalBounds(game->ghost[0][i].ghost);
        if (sfFloatRect_contains(&ghost, bulet.x, bulet.y))
            boooom(game, i, 0);
    }
    for (int i = 0; i < MAX_FANTOME_2; i++) {
        ghost = sfSprite_getGlobalBounds(game->ghost[1][i].ghost);
        if (sfFloatRect_contains(&ghost, bulet.x, bulet.y))
            boooom(game, i, 1);
    }
    for (int i = 0; i < MAX_FANTOME_3; i++) {
        ghost = sfSprite_getGlobalBounds(game->ghost[2][i].ghost);
        if (sfFloatRect_contains(&ghost, bulet.x, bulet.y))
            boooom(game, i, 2);
    }
}

void move_ghost(game_t *game)
{
    move_player(game, game->map[1].map);
    move_player(game, game->map[1].map_hit);
    move_player(game, game->map[1].key_e);
    move_player(game, game->map[1].next);
    for (int i = 0; i < MAX_FANTOME_1; i++)
        move_player(game, game->ghost[0][i].ghost);
    for (int i = 0; i < MAX_FANTOME_2; i++)
        move_player(game, game->ghost[1][i].ghost);
    for (int i = 0; i < MAX_FANTOME_3; i++)
        move_player(game, game->ghost[2][i].ghost);
}

float set_speed2(int i, game_t *game)
{
    if (game->dif == 2) {
        if (i == 0)
            return 1.5f;
        if (i == 1)
            return 2;
        if (i == 2)
            return 4;
    }
    return 0.0;
}

float set_speed(int i, game_t *game)
{
    if (game->dif == 0) {
        if (i == 0)
            return 0.4f;
        if (i == 1)
            return 1;
        if (i == 2)
            return 2;
    }
    else if (game->dif == 1) {
        if (i == 0)
            return 0.8f;
        if (i == 1)
            return 1.5f;
        if (i == 2)
            return 2.5f;
    }
    else return set_speed2(i, game);
    return 0.0;
}

void change_ghost_side(game_t *game, int n, int i)
{
    sfVector2f scale = sfSprite_getScale(game->ghost[n][i].ghost);

    if (n == 2)
        return;
    if (scale.x < 0)
        scale.x *= -1;
    if (n == 1) {
        if (sfSprite_getPosition(game->ghost[n][i].ghost).x < 900)
            sfSprite_setScale(game->ghost[n][i].ghost,
            start_point(-1*scale.x, 1*scale.y));
        else
            sfSprite_setScale(game->ghost[n][i].ghost, scale);
    }
    if (n == 0) {
        if (sfSprite_getPosition(game->ghost[n][i].ghost).x < 900)
            sfSprite_setScale(game->ghost[n][i].ghost, scale);
        else
            sfSprite_setScale(game->ghost[n][i].ghost,
            start_point(-+1*scale.x, 1*scale.y));
    }
}