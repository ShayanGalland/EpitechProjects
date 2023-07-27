/*
** EPITECH PROJECT, 2022
** screen_death.c
** File description:
** screen_death
*/

#include "include.h"

void screen_death(game_t game*)
{
    ptr->first_back.t = sfTexture_createFromFile("", NULL);
    ptr->first_back.s = sfSprite_create();
    ptr->first_back.v = (sfVector2f){1.5, 1.5};
    ptr->prs.t = sfTexture_createFromFile("", NULL);
    ptr->prs.s = sfSprite_create();
    ptr->prs.v = (sfVector2f) {4, 4};
    ptr->prs.p = (sfVector2f) {0, 120};
}

void menu(game_t *game)
{
    game->menu.screen = get_new_item("asset/sprites/screen.jpg",
    (sfVector2f){0, 0}, 0, get_rects(0, 0, 1800, 1000));
    game->menu.quit = set_txt("Exit Game", 100, 900, 0.8);
    game->menu.black_screen = get_new_item("asset/sprites/black_screen.png",
    (sfVector2f){0, 0}, 0, get_rects(0, 0, 1800, 1000));
    game->menu.back = set_txt("Back", 100, 900, 0.8);
    (sfVector2f){500, 600}, 0, get_rects(0, 0, 25, 500));
    (sfVector2f){500, 600}, 0, get_rects(0, 0, 25, 250));
}

void exit(game_t *game)
{
    sfVector2i mouse = sfMouse_getPosition(game->window);

    if (check_text(get_rects(0, 0, 40, 280), (sfVector2f){100, 890},
    game->cursor.pos, &game->menu.quit) == 1)
        if (game->event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(game->window);
}

void button(game_t *game)
{
    if (check_text(get_rects(0, 0, 40, 280), (sfVector2f){100, 690},
    game->cursor.pos, &game->menu.play) == 1)
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->step = Exit;
            game->started = 1;
        }
    if (game->event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(game->window);
}

void screen_death(game_t *game)
{
    game->map[1].text_map = sfTexture_createFromFile
    ("asset/death/game_over.png", NULL);
    game->map[1].map_hit = init_sprite(game->map[1].text_map_hit);
    game->map[1].next = init_sprite(game->map[1].text_next);
    game->map[1].key_e = init_sprite(game->map[1].text_key_e);
}
