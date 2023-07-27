/*
** EPITECH PROJECT, 2022
** init
** File description:
** init
*/

#include "include.h"

item_t get_new_item(char *path, sfVector2f pos,
float refresh_rate, sfIntRect rect)
{
    item_t item;

    item.clock = sfClock_create();
    item.timer = refresh_rate;
    item.sprite = sfSprite_create();
    item.texture = sfTexture_createFromFile(path, NULL);
    item.rect = rect;
    item.pos.x = pos.x;
    item.pos.y = pos.y;
    sfSprite_setTexture(item.sprite, item.texture, sfTrue);
    return item;
}

static void create_window(game_t *game)
{
    sfVideoMode screen;

    screen.width = 1800;
    screen.height = 1000;
    screen.bitsPerPixel = 64;
    game->window = sfRenderWindow_create(screen,
    "my_rpg", sfDefaultStyle, NULL);
}

void set_pos_ghost(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++)
        sfSprite_setPosition(game->ghost[0][i].ghost, start_point(-875, -87));
    for (int i = 0; i < MAX_FANTOME_2; i++)
        sfSprite_setPosition(game->ghost[1][i].ghost, start_point(-875, -87));
    for (int i = 0; i < MAX_FANTOME_3; i++)
        sfSprite_setPosition(game->ghost[2][i].ghost, start_point(-875, -87));
}

void set_spawned_ghost(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++)
        game->ghost[0][i].spawned = 0;
    for (int i = 0; i < MAX_FANTOME_2; i++)
        game->ghost[1][i].spawned = 0;
    for (int i = 0; i < MAX_FANTOME_3; i++)
        game->ghost[2][i].spawned = 0;
    for (int i = 0; i < MAX_FANTOME_1; i++)
        game->ghost[0][i].scale = 0.0f;
    for (int i = 0; i < MAX_FANTOME_2; i++)
        game->ghost[1][i].scale = 0.0f;
    for (int i = 0; i < MAX_FANTOME_3; i++)
        game->ghost[2][i].scale = -0.3f;
}

void init_game(game_t *game)
{
    game->cursor = get_new_item("asset/sprites/screen.jpg",
    (sfVector2f){0, 0}, 0, get_rects(0, 0, 50, 50));
    init_values(game);
    default_value(game);
    create_menu(game);
    create_pause(game);
    create_window(game);
    create_sprites(game);
    create_inventory(game);
    create_tuto(game);
    create_hint(&game->hint);
    create_music(&game->music);
    create_level(&game->level);
    set_sprite(game);
    set_pos_ghost(game);
    set_spawned_ghost(game);
}