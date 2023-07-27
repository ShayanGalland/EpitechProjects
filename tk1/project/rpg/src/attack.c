/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void spawn_zone1(game_t *game, sfVector2f cord, int spawned)
{
    sfVector2f pos = start_point(sfSprite_getPosition(game->map[1].map).x
    , sfSprite_getPosition(game->map[1].map).y);
    int count = 0;

    if (pos.x < cord.x+500 && pos.x > cord.x-500 && pos.y < cord.y+500
    && pos.y > cord.y-500 && game->is_spawned[spawned] == 0)
        ;
    else
        return;
    for (int i = 0; i < MAX_FANTOME_1; i++) {
        count = spawning_in_zone1(game, i, count, cord);
        if (count >= MAX_FANTOME_1/14)
            break;
    }
    game->is_spawned[spawned] = 1;
}

void spawn_zone2(game_t *game, sfVector2f cord, int spawned)
{
    sfVector2f pos = start_point(sfSprite_getPosition(game->map[1].map).x
    , sfSprite_getPosition(game->map[1].map).y);
    int count = 0;

    if (pos.x < cord.x+500 && pos.x > cord.x-500 && pos.y < cord.y+500
    && pos.y > cord.y-500 && game->is_spawned[spawned] == 0)
        ;
    else
        return;
    for (int i = 0; i < MAX_FANTOME_2; i++) {
        count = spawning_in_zone2(game, i, count, cord);
        if (count >= MAX_FANTOME_2/10)
            break;
    }
    game->is_spawned[spawned] = 1;
}

void spawn_zone3(game_t *game, sfVector2f cord, int spawned)
{
    sfVector2f pos = start_point(sfSprite_getPosition(game->map[1].map).x
    , sfSprite_getPosition(game->map[1].map).y);
    int count = 0;

    if (pos.x < cord.x+500 && pos.x > cord.x-500 && pos.y < cord.y+500
    && pos.y > cord.y-500 && game->is_spawned[spawned] == 0)
        ;
    else
        return;
    for (int i = 0; i < MAX_FANTOME_3; i++) {
        count = spawning_in_zone3(game, i, count, cord);
        if (count >= MAX_FANTOME_3/7)
            break;
    }
    game->is_spawned[spawned] = 1;
}

void other_zone(game_t *game)
{
    spawn_zone2(game, start_point(-5060, -12730), 14);
    spawn_zone2(game, start_point(-4310, -11460), 15);
    spawn_zone2(game, start_point(-4300, -8270), 16);
    spawn_zone2(game, start_point(-4560, -2790), 17);
    spawn_zone2(game, start_point(-5055, -1730), 18);
    spawn_zone2(game, start_point(-3285, -1980), 19);
    spawn_zone2(game, start_point(-4130, 130), 20);
    spawn_zone2(game, start_point(-1865, -550), 21);
    spawn_zone2(game, start_point(-1865, 50), 22);
    spawn_zone2(game, start_point(320, -375), 23);
    spawn_zone3(game, start_point(-3830, -4860), 24);
    spawn_zone3(game, start_point(-4345, -6880), 25);
    spawn_zone3(game, start_point(-5000, -8230), 26);
    spawn_zone3(game, start_point(-4280, -9740), 27);
    spawn_zone3(game, start_point(-5020, -11340), 28);
    spawn_zone3(game, start_point(-4345, -13100), 29);
    spawn_zone3(game, start_point(-5020, -13950), 30);
}

void ghost_attack(game_t *game)
{
    if (game->map_select == 2) {
        spawn_zone1(game, start_point(-1150, 35), 0);
        spawn_zone1(game, start_point(-1150, -550), 1);
        spawn_zone1(game, start_point(-2540, 50), 2);
        spawn_zone1(game, start_point(-2535, -540), 3);
        spawn_zone1(game, start_point(-3295, -880), 4);
        spawn_zone1(game, start_point(-5220, -970), 5);
        spawn_zone1(game, start_point(-5315, 130), 6);
        spawn_zone1(game, start_point(-3630, -1970), 7);
        spawn_zone1(game, start_point(-3370, -2980), 8);
        spawn_zone1(game, start_point(-4130, -3900), 9);
        spawn_zone1(game, start_point(-4300, -5580), 10);
        spawn_zone1(game, start_point(-5060, -6340), 11);
        spawn_zone1(game, start_point(-5050, -10040), 12);
        spawn_zone1(game, start_point(-4380, -13980), 13);
        other_zone(game);
    }
}