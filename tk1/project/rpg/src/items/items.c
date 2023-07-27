/*
** EPITECH PROJECT, 2022
** items
** File description:
** items
*/

#include "include.h"

static void init_object(object_t *object, char *name, int is_active, int id)
{
    object->active = is_active;
    object->name = name;
    object->used = 0;
    object->id = id;
    object->amount = 0;
}

void create_items(game_t *game)
{
    game->items.object = malloc(sizeof(object_t) * MAX_ITEMS);
    game->items.object[FLASHLIGHT].item = get_new_item("asset/items/"
    "flashlight.png", (sfVector2f){1020, 435}, 0, get_rects(0, 0, 40, 60));
    init_object(&game->items.object[0], "Flashlight", 0, 0);
    game->items.object[KEY].item = get_new_item("asset/items/key.png",
    (sfVector2f){-100, -100}, 0, get_rects(0, 0, 30, 60));
    init_object(&game->items.object[1], "Key\n(active)", 1, 1);
    game->items.object[HEAL].item = get_new_item("asset/items/"
    "heal_potion.png", (sfVector2f){-100, -100}, 0, get_rects(0, 0, 60, 60));
    init_object(&game->items.object[2], "Healing potion\n(active)", 1, 2);
    game->items.object[SCROLL].item = get_new_item("asset/items/scroll.png",
    (sfVector2f){-100, -100}, 0, get_rects(0, 0, 60, 60));
    init_object(&game->items.object[3], "Quest scoll", 0, 2);
}

static int *delete_items(int *slots, int id)
{
    for (int i = 0; i < MAX_INVENTORY - 1; i++) {
        if (slots[i] == id) {
            slots[i] = -1;
            break;
        }
    }
    return slots;
}

void do_active(game_t *game, object_t *object)
{
    if (game->event.type == sfEvtMouseButtonPressed && object->active == 1) {
        object->item.pos.x = -100;
        object->item.pos.y = -100;
        object->used = 1;
        game->items.in_slots = delete_items(game->items.in_slots, object->id);
    }
}

void display_items_hover(game_t *game)
{
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (game->cursor.pos.x >= game->items.object[i].item.pos.x
        && game->cursor.pos.x <= game->items.object[i].item.pos.x +
        game->items.object[i].item.rect.width
        && game->cursor.pos.y >= game->items.object[i].item.pos.y
        && game->cursor.pos.y <= game->items.object[i].item.pos.y +
        game->items.object[i].item.rect.height) {
            game->items.show_item = set_txt(game->items.object[i].name,
            game->cursor.pos.x, game->cursor.pos.y, 0.5);
            game->items.is_hover = 1;
            do_active(game, &game->items.object[i]);
            break;
        } else {
            game->items.is_hover = 0;
        }
    }
}
