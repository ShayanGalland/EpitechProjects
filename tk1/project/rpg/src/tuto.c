/*
** EPITECH PROJECT, 2022
** tuto
** File description:
** tuto
*/

#include "include.h"

void create_tuto(game_t *game)
{
    game->tuto.text = malloc(sizeof(char *) * 8);
    game->tuto.text[0] = TUTO1;
    game->tuto.text[1] = TUTO2;
    game->tuto.text[2] = TUTO3;
    game->tuto.text[3] = TUTO4;
    game->tuto.text[4] = TUTO5;
    game->tuto.text[5] = TUTO6;
    game->tuto.text[6] = TUTO7;
    game->tuto.text[7] = NULL;
}

void tuto_events(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && game->delay > 0) {
        game->tuto.step++;
        game->delay = 0;
    }
}

void do_tuto_dialogue(game_t *game)
{
    if (game->tuto.text[game->tuto.step] == NULL) {
        game->step = GAME;
        game->delay = 0;
        sfSound_stop(game->music.car);
        sfMusic_play(game->music.main);
        return;
    }
    game->delay++;
    if (game->delay == my_strlen(game->tuto.text[game->tuto.step]) * 100) {
        game->tuto.step++;
        game->delay = 0;
    }
    sfRenderWindow_drawText(game->window, set_txt(
    game->tuto.text[game->tuto.step], 300, 770, 0.8), NULL);
}

void display_tuto(game_t *game)
{
    if (game->step == TUTO) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.black_screen.sprite, NULL);
        sfSprite_setTextureRect(game->hero.hero, get_rects(0, 130, 50, 50));
        sfSprite_setScale(game->hero.hero, (sfVector2f){3, 3});
        sfRenderWindow_drawSprite(game->window, game->hero.hero, NULL);
        sfRenderWindow_drawSprite(game->window, game->pnj.box, NULL);
        do_tuto_dialogue(game);
    }
}