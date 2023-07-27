/*
** EPITECH PROJECT, 2022
** init
** File description:
** init
*/

#include "include.h"

void do_hint(game_t *game)
{
    if (game->hint.step == 0) {
        display_hint(game, game->hint.button,
        set_txt(HINT01, 1300, 70, 0.7), (sfVector2f){0.5, 0.5});
    }
    if (game->hint.step == 1) {
        display_hint(game, game->hint.mouse,
        set_txt(HINT02, 1300, 70, 0.7), (sfVector2f){0.8, 0.8});
    }
    if (game->hint.step == 2) {
        display_hint(game, game->items.object[KEY].item,
        set_txt(HINT03, 1300, 70, 0.7), (sfVector2f){1, 1});
    }
}

void display_all(game_t *game)
{
    display_menu(game);
    display_game(game);
    display_tuto(game);
    display_pause(game);
    display_inventory(game);
}

void display_game(game_t *game)
{
    if (game->step != MENU && game->step != SETTING && game->step != TUTO) {
        draw_sprites(game);
        do_hint(game);
    }
}
