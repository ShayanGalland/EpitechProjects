/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include "include.h"

void game_events(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->delay == 0) {
        game->step = PAUSE;
        game->delay = 50;
    }
    if (sfKeyboard_isKeyPressed(sfKeyI) && game->delay == 0) {
        game->step = INVENTORY;
        game->delay = 50;
        game->hero.side = 127;
    }
}

static void do_all_events(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    menu_events(game);
    if (game->step == TUTO)
        tuto_events(game);
    if (game->step == GAME)
        game_events(game);
    if (game->step == PAUSE)
        pause_events(game, game->event);
    if (game->step == INVENTORY)
        inventory_events(game);
}

void manage_events(game_t *game)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(game->window);
    game->cursor.pos.x = mouse.x;
    game->cursor.pos.y = mouse.y;
    if (game->step != TUTO)
        if (game->delay > 0)
                game->delay -= 1;
    level_up(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        do_all_events(game);
    }
}