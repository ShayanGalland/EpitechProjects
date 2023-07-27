/*
** EPITECH PROJECT, 2022
** menu settings
** File description:
** menu settings
*/

#include "include.h"

void manage_dif(menu_t *menu, int *dif)
{
    *dif += 1;
    if (*dif >= 3)
        *dif = 0;
    if (*dif == 0)
        menu->dif = set_txt("Easy", 500, 400, 0.8);
    if (*dif == 1)
        menu->dif = set_txt("Normal", 500, 400, 0.8);
    if (*dif == 2)
        menu->dif = set_txt("Hard", 500, 400, 0.8);
}

void manage_fps(menu_t *menu, int *fps)
{
    *fps += 30;
    if (*fps > 90)
        *fps = 30;
    if (*fps == 30)
        menu->fps = set_txt("30", 500, 500, 0.8);
    if (*fps == 60)
        menu->fps = set_txt("60", 500, 500, 0.8);
    if (*fps == 90)
        menu->fps = set_txt("90", 500, 500, 0.8);
}

void volume_bar(game_t *game)
{
    if (game->cursor.pos.x >= 500 && game->cursor.pos.x <= 1000
    && game->cursor.pos.y >= 590 && game->cursor.pos.y <= 630) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->vol = (game->cursor.pos.x / 5) - 100;
            game->menu.filled_vol.rect = get_rects(0, 0, 25,
            game->cursor.pos.x - 500);
            sfMusic_setVolume(game->music.main, (float)game->vol);
        }
    }
}
