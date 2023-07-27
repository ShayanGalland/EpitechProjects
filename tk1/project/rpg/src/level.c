/*
** EPITECH PROJECT, 2022
** level
** File description:
** level
*/

#include "include.h"

void create_level(level_t *level)
{
    char lvl[5];
    char exp[5];
    char limit[5];

    level->exp = 0;
    level->elapsed = 0;
    level->exp_bar = get_new_item("asset/level/exp_bar.jpg",
    (sfVector2f){750, 700}, 0, get_rects(0, 0, 30, 300));
    level->exp_gui = get_new_item("asset/level/exp_gui.jpg",
    (sfVector2f){750, 700}, 0, get_rects(0, 0, 30, 300));
    level->limit = 60;
    level->level = 1;
    my_itoa(lvl, level->level);
    my_itoa(limit, level->limit);
    my_itoa(exp, level->exp);
    level->txt = set_txt(lvl, 1090, 705, 0.8);
    level->limit_txt = set_txt(limit, 940, 707, 0.6);
    level->exp_txt = set_txt(exp, 820, 707, 0.6);
}

void display_lvl_bar(game_t *game)
{
    char exp[5];
    char limit[5];

    my_itoa(exp, game->level.exp);
    my_itoa(limit, game->level.limit);
    game->level.limit_txt = set_txt(limit, 940, 707, 0.6);
    game->level.exp_txt = set_txt(exp, 820, 707, 0.6);
    display_sprites(game->level.exp_gui, game->window);
    game->level.exp_bar.rect = get_rects(0, 0, 30,
    game->level.exp * (300 / game->level.limit));
    display_sprites(game->level.exp_bar, game->window);
    sfRenderWindow_drawText(game->window, game->level.txt, NULL);
    sfRenderWindow_drawText(game->window, game->level.limit_txt, NULL);
    sfRenderWindow_drawText(game->window, set_txt("/", 910, 707, 0.6), NULL);
    sfRenderWindow_drawText(game->window, game->level.exp_txt, NULL);
}

void gain_exp(game_t *game)
{
    game->level.elapsed++;
    if (game->level.elapsed > 6) {
        game->level.exp++;
        game->level.elapsed = 0;
    }
}

void level_up(game_t *game)
{
    char lvl[5];

    if (game->level.exp >= game->level.limit) {
        game->level.level++;
        game->level.limit += 20;
        game->level.exp = 0;
        game->hero.less_life += 0.08;
        my_itoa(lvl, game->level.level);
        game->level.txt = set_txt(lvl, 1090, 705, 0.8);
    }
}