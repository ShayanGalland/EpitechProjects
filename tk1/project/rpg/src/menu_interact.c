/*
** EPITECH PROJECT, 2022
** menu button
** File description:
** menu button
*/

#include "include.h"

void fps_button(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 70), (sfVector2f){500, 490},
    game->cursor.pos, &game->menu.fps) == 1)
        if (game->event.type == sfEvtMouseButtonPressed)
            manage_fps(&game->menu, &game->fps);
}

void difficulty_button(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 150), (sfVector2f){500, 390},
    game->cursor.pos, &game->menu.dif) == 1) {
        if (game->event.type == sfEvtMouseButtonPressed)
            manage_dif(&game->menu, &game->dif);
    }
}

void setting_back(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 120), (sfVector2f){100, 890},
    game->cursor.pos, &game->menu.back) == 1) {
        if (game->event.type == sfEvtMouseButtonPressed && game->started == 0)
            game->step = MENU;
        if (game->event.type == sfEvtMouseButtonPressed && game->started == 1)
            game->step = GAME;
    }
}