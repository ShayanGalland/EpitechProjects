/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void key_door(game_t *game)
{
    sfFloatRect b_key1 = sfSprite_getGlobalBounds(game->key.key1);
    sfFloatRect b_key2 = sfSprite_getGlobalBounds(game->key.key2);
    sfFloatRect b_key3 = sfSprite_getGlobalBounds(game->key.key3);
    sfVector2i mouse = sfMouse_getPosition((sfWindow*)game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&b_key1, mouse.x, mouse.y)) {
            game->key.key1f = 1;
            add_to_inventory(game, &game->items.object[KEY]);
            game->hint.step = 2;
        }
        if (sfFloatRect_contains(&b_key2, mouse.x, mouse.y)) {
            game->key.key2f = 1;
            add_to_inventory(game, &game->items.object[KEY]);
            add_to_inventory(game, &game->items.object[HEAL]);
        }
        if (sfFloatRect_contains(&b_key3, mouse.x, mouse.y)) {
            game->key.key3f = 1;
            add_to_inventory(game, &game->items.object[KEY]);
        }
    }
}

int next(game_t *game, sfSprite *the_next, sfSprite *key)
{
    sfVector2f pos_hero;
    sfFloatRect next = sfSprite_getGlobalBounds(the_next);

    pos_hero.x = sfSprite_getPosition(game->hero.hero).x;
    pos_hero.y = sfSprite_getPosition(game->hero.hero).y;
    if (sfFloatRect_contains(&next, pos_hero.x, pos_hero.y)) {
        sfSprite_setPosition(key, sfSprite_getPosition(the_next));
        if (!sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_drawSprite(game->window, key, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            game->map_select = 2;
            sfSprite_setPosition(the_next, start_point(-99, -99));
            game->hint.step = 1;
            return 1;
        }
    }
    return 0;
}

void select_map(game_t *game)
{
    if (next(game, game->map[0].next, game->map[0].key_e)) {
        sfSprite_setPosition(game->map[1].next, start_point(690, 400));
        sfSprite_setPosition(game->map[1].map, start_point(753, 247));
        sfSprite_setPosition(game->map[1].map_hit, start_point(753, 247));
        game->map_select = 2;
    }
    if (next(game, game->map[1].next, game->map[1].key_e)) {
        sfSprite_setPosition(game->map[0].next, start_point(790, 280));
        sfSprite_setPosition(game->map[0].map, start_point(155.5f, 118.25f));
        sfSprite_setPosition(game->map[0].map_hit, start_point(155.5f, 118));
        sfSprite_setPosition(game->pnj.pnj, start_point(390, 1120));
        sfSprite_setPosition(game->pnj.e, start_point(350, 1140));
        game->map_select = 1;
    }
}

void other_world(game_t *game)
{
    sfVector2f pos;

    pos.x = sfSprite_getPosition(game->map[1].map).x;
    pos.y = sfSprite_getPosition(game->map[1].map).y;
    if (pos.y < -15800 && pos.x < -6200) {
        sfRenderWindow_drawSprite(game->window, game->map[1].next, NULL);
        game->other_world = 1;
    }
    if (game->other_world == 1) {
        game->map_select = 0;
    }
}

void switch_doors(game_t *game, int num, int key)
{
    sfVector2f pos;

    pos.x = sfSprite_getPosition(game->map[1].map).x;
    pos.y = sfSprite_getPosition(game->map[1].map).y;
    if (key == 1 && game->items.object[1].used == 1) {
        game->map[1].map_hit = init_sprite(game->map[num].text_map_hit);
        sfSprite_setPosition(game->map[1].map_hit, pos);
        sfSprite_setScale(game->map[1].map_hit, start_point(7, 7));
        game->map[1].map_collision = NULL;
        game->map[1].map_collision = game->map[num].map_collision;
    }
}