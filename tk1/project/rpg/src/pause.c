/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
*/

#include "include.h"

void create_pause(game_t *game)
{
    game->pause.resume = set_txt("RESUME", 780, 500, 1);
    game->pause.setting = set_txt("SETTINGS", 740, 650, 1);
    game->pause.exit = set_txt("EXIT GAME", 730, 800, 1);
}

void pause_events(game_t *game, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->delay == 0) {
        game->delay = 50;
            game->step = GAME;
    }
    resume_button(game, event, game->cursor.pos);
    pause_settings(game, event, game->cursor.pos);
    pause_exit(game, event, game->cursor.pos);
}

void display_pause(game_t *game)
{
    if (game->step == PAUSE) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.black_screen.sprite, NULL);
        sfRenderWindow_drawText(game->window,
        set_txt("PAUSE", 800, 200, 1), NULL);
        sfRenderWindow_drawText(game->window, game->pause.resume, NULL);
        sfRenderWindow_drawText(game->window, game->pause.setting, NULL);
        sfRenderWindow_drawText(game->window, game->pause.exit, NULL);
    }
}
