/*
** EPITECH PROJECT, 2022
** inventory
** File description:
** inventory
*/

#include "include.h"

void create_slots(game_t *game)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < MAX_INVENTORY; i++) {
        game->items.slots[i] = get_new_item("asset/inventory/frame.png",
        (sfVector2f){150 + x, 350 + y}, 0, get_rects(0, 0, 100, 100));
        x += 130;
        if (x >= 520) {
            x = 0;
            y += 130;
        }
    }
    game->items.slots[MAX_INVENTORY - 1].pos = (sfVector2f){1000, 400};
    game->items.in_slots = malloc(sizeof(int) * (MAX_INVENTORY - 1));
    for (int i = 0; i < MAX_INVENTORY - 1; i++)
        game->items.in_slots[i] = -1;
}

void create_inventory(game_t *game)
{
    game->items.screen = get_new_item("asset/inventory/screen.png",
    (sfVector2f){0, 0}, 0, get_rects(0, 0, 1800, 1000));
    game->items.slots = malloc(sizeof(item_t) * MAX_INVENTORY);
    create_slots(game);
    create_items(game);
}

void inventory_events(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyI) ||
    sfKeyboard_isKeyPressed(sfKeyEscape)) && game->delay == 0) {
        game->step = GAME;
        game->delay = 50;
    }
    display_items_hover(game);
    if (game->items.object[2].used == 1) {
        game->hero.less_life += 0.08;
        game->items.object[2].used = 0;
    }
}

void add_to_inventory(game_t *game, object_t *item)
{
    for (int i = 0; i < MAX_INVENTORY - 1; i++) {
        if (item->item.pos.x == game->items.slots[i].pos.x +
            (80 - item->item.rect.width)
            && item->item.pos.y == game->items.slots[i].pos.y +
            (80 - item->item.rect.height))
            break;
        if (game->items.in_slots[i] == -1) {
            item->item.pos.x = game->items.slots[i].pos.x +
            (80 - item->item.rect.width);
            item->item.pos.y = game->items.slots[i].pos.y +
            (80 - item->item.rect.height);
            game->items.in_slots[i] = item->id;
            item->used = 0;
            break;
        }
    }
}

void display_inventory(game_t *game)
{
    if (game->step == INVENTORY) {
        sfSprite_setScale(game->hero.hero, start_point(4, 4));
        create_and_anim_hero(game);
        sfRenderWindow_drawSprite(game->window,
        game->menu.black_screen.sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->items.screen.sprite,
        NULL);
        sfRenderWindow_drawSprite(game->window, game->hero.hero, NULL);
        for (int i = 0; i < MAX_INVENTORY; i++)
            display_sprites(game->items.slots[i], game->window);
        for (int i = 0; i < MAX_ITEMS; i++)
            display_sprites(game->items.object[i].item, game->window);
        if (game->items.is_hover == 1) {
            sfRenderWindow_drawText(game->window, game->items.show_item, NULL);
        }
        display_lvl_bar(game);
    } else
        sfSprite_setScale(game->hero.hero, start_point(2, 2));
}
