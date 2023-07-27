/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#include "include.h"

void create_menu(game_t *game)
{
    game->menu.screen = get_new_item("asset/sprites/screen.jpg",
    (sfVector2f){0, 0}, 0, get_rects(0, 0, 1800, 1000));
    game->menu.play = set_txt("Start Game", 100, 700, 0.8);
    game->menu.setting = set_txt("Settings", 100, 800, 0.8);
    game->menu.quit = set_txt("Exit Game", 100, 900, 0.8);
    game->menu.black_screen = get_new_item("asset/sprites/black_screen.png",
    (sfVector2f){0, 0}, 0, get_rects(0, 0, 1800, 1000));
    game->menu.back = set_txt("Back", 100, 900, 0.8);
    game->menu.dif = set_txt("Normal", 500, 400, 0.8);
    game->menu.fps = set_txt("60", 500, 500, 0.8);
    game->menu.empty_vol = get_new_item("asset/sprites/empty_volume.png",
    (sfVector2f){500, 600}, 0, get_rects(0, 0, 25, 500));
    game->menu.filled_vol = get_new_item("asset/sprites/filled_volume.png",
    (sfVector2f){500, 600}, 0, get_rects(0, 0, 25, 250));
}

void display_sprites(item_t item, sfRenderWindow *window)
{
    sfSprite_setPosition(item.sprite, (sfVector2f){
        item.pos.x, item.pos.y});
    sfSprite_setTextureRect(item.sprite, item.rect);
    sfRenderWindow_drawSprite(window, item.sprite, NULL);
}

void display_menu_settings(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.screen.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.black_screen.sprite,
    NULL);
    sfRenderWindow_drawText(game->window, set_txt("SETTINGS", 100, 100, 1),
    NULL);
    sfRenderWindow_drawText(game->window, set_txt("Difficulty : ", 100, 400,
    0.8), NULL);
    sfRenderWindow_drawText(game->window, game->menu.dif, NULL);
    sfRenderWindow_drawText(game->window, set_txt("FPS :", 100, 500, 0.8),
    NULL);
    sfRenderWindow_drawText(game->window, game->menu.fps, NULL);
    sfRenderWindow_drawText(game->window, set_txt("Volume :", 100, 600, 0.8),
    NULL);
    sfRenderWindow_drawText(game->window, set_txt("-Skins-", 1200, 200, 0.8),
    NULL);
    sfRenderWindow_drawText(game->window, game->menu.back, NULL);
    display_sprites(game->menu.empty_vol, game->window);
    display_sprites(game->menu.filled_vol, game->window);
}

void display_menu(game_t *game)
{
    if (game->step == MENU) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.screen.sprite, NULL);
        sfRenderWindow_drawText(game->window, game->menu.play, NULL);
        sfRenderWindow_drawText(game->window, game->menu.setting, NULL);
        sfRenderWindow_drawText(game->window, game->menu.quit, NULL);
    }
    if (game->step == SETTING) {
        display_menu_settings(game);
    }
}

void menu_events(game_t *game)
{
    if (game->step == MENU) {
        play_button(game);
        setting_button(game);
        exit_button(game);
    }
    if (game->step == SETTING) {
        setting_back(game);
        difficulty_button(game);
        fps_button(game);
        volume_bar(game);
    }
}
