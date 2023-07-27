/*
** EPITECH PROJECT, 2022
** menu button
** File description:
** menu button
*/

#include "include.h"

void play_button(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 280), (sfVector2f){100, 690},
    game->cursor.pos, &game->menu.play) == 1)
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music.car);
            game->step = TUTO;
            game->started = 1;
        }
}

void setting_button(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 280), (sfVector2f){100, 790},
    game->cursor.pos, &game->menu.setting) == 1)
        if (game->event.type == sfEvtMouseButtonPressed)
            game->step = SETTING;
}

void exit_button(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 280), (sfVector2f){100, 890},
    game->cursor.pos, &game->menu.quit) == 1)
        if (game->event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(game->window);
}

int check_text(sfIntRect rect, sfVector2f pos, sfVector2f mouse, sfText **text)
{
    if (mouse.x >= pos.x && mouse.x <= pos.x + rect.width
    && mouse.y >= pos.y && mouse.y <= pos.y + rect.height) {
        sfText_setScale(*text, (sfVector2f){0.7, 0.7});
        return 1;
    } else {
        sfText_setScale(*text, (sfVector2f){0.8, 0.8});
    }
    return 0;
}
