/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

static void cursor_attack(game_t *game)
{
    sfVector2f mouse_pos;

    mouse_pos.x = sfMouse_getPosition((sfWindow*)game->window).x;
    mouse_pos.y = sfMouse_getPosition((sfWindow*)game->window).y;
    sfSprite_setPosition(game->hero.shoot.cursor, mouse_pos);
    game->hero.shoot.dist = distance(game->hero.hero,game->hero.shoot.cursor);
}

static void shoot_to_cursor(game_t *game, float elapsed)
{
    sfVector2f path;

    path.x = game->hero.shoot.x - sfSprite_getPosition(game->hero.hero).x-60;
    path.y = game->hero.shoot.y - sfSprite_getPosition(game->hero.hero).y-60;
    sfSprite_move(game->hero.shoot.ball,start_point(path.x*
    game->hero.shoot.spd*elapsed, path.y*game->hero.shoot.spd*elapsed));
    if (distance(game->hero.hero, game->hero.shoot.ball) >
    game->hero.shoot.dist) {
        sfSprite_setPosition(game->hero.shoot.ball, start_point(-99, -99));
    }
}

void handle_shoot(game_t *game, float elapsed)
{
    sfVector2f pos;

    sfSprite_setPosition(game->hero.shoot.cursor, start_point(-99, -99));
    pos.x = sfSprite_getPosition(game->hero.hero).x+27;
    pos.y = sfSprite_getPosition(game->hero.hero).y+60;
    if (sfSprite_getPosition(game->hero.shoot.ball).x == -99) {
    game->hero.shoot.x = sfMouse_getPosition((sfWindow*)game->window).x;
    game->hero.shoot.y = sfMouse_getPosition((sfWindow*)game->window).y;
    }
    if (game->event.type == sfEvtMouseButtonPressed &&
    sfSprite_getPosition(game->hero.shoot.ball).x == -99) {
        cursor_attack(game);
        sfSprite_setPosition(game->hero.shoot.ball, pos);
        sfSound_play(game->music.shoot);
    }
    if (sfSprite_getPosition(game->hero.shoot.ball).x != -99) {
        shoot_to_cursor(game, elapsed);
        move_player(game, game->hero.shoot.ball);
    }
}