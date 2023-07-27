/*
** EPITECH PROJECT, 2022
** pause button
** File description:
** pause button
*/

#include "include.h"

void resume_button(game_t *game, sfEvent event, sfVector2f mouse)
{
    if ((mouse.x >= 780 && mouse.x <= 1030)
    && (mouse.y >= 500 && mouse.y <= 560)) {
        sfText_setScale(game->pause.resume, (sfVector2f){0.9, 0.9});
        sfText_setPosition(game->pause.resume, (sfVector2f){790, 505});
        if (event.type == sfEvtMouseButtonPressed)
            game->step = GAME;
    } else {
        sfText_setScale(game->pause.resume, (sfVector2f){1, 1});
        sfText_setPosition(game->pause.resume, (sfVector2f){780, 500});
    }
}

void pause_settings(game_t *game, sfEvent event, sfVector2f mouse)
{
    if ((mouse.x >= 740 && mouse.x <= 1080)
    && (mouse.y >= 650 && mouse.y <= 710)) {
        sfText_setScale(game->pause.setting, (sfVector2f){0.9, 0.9});
        sfText_setPosition(game->pause.setting, (sfVector2f){750, 655});
        if (event.type == sfEvtMouseButtonPressed)
            game->step = SETTING;
    } else {
        sfText_setScale(game->pause.setting, (sfVector2f){1, 1});
        sfText_setPosition(game->pause.setting, (sfVector2f){740, 650});
    }
}

void pause_exit(game_t *game, sfEvent event, sfVector2f mouse)
{
    if ((mouse.x >= 730 && mouse.x <= 1080)
    && (mouse.y >= 800 && mouse.y <= 860)) {
        sfText_setScale(game->pause.exit, (sfVector2f){0.9, 0.9});
        sfText_setPosition(game->pause.exit, (sfVector2f){740, 805});
        if (event.type == sfEvtMouseButtonPressed) {
            game->step = MENU;
            game->started = 0;
            game->menu.play = set_txt("Continue", 100, 700, 0.8);
        }
    } else {
        sfText_setScale(game->pause.exit, (sfVector2f){1, 1});
        sfText_setPosition(game->pause.exit, (sfVector2f){730, 800});
    }
}
