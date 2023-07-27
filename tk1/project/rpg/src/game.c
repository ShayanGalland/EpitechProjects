/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void pluie(game_t *game, float elapsed)
{
    sfSprite_move(game->pluie, start_point(0, 2000 * elapsed));
    if (sfSprite_getPosition(game->pluie).y > 0)
        sfSprite_setPosition(game->pluie, start_point(0, -2000));
}

void manage_door(game_t *game, float elapsed)
{
    if (game->map_select == 1)
        pluie(game, elapsed);
    key_door(game);
    switch_doors(game, 2, game->key.key1f);
    switch_doors(game, 3, game->key.key2f);
    switch_doors(game, 4, game->key.key3f);
}

void manage_gameplay(game_t *game, float elapsed)
{
    game->game_time += elapsed;
    game->pnj.press_anim += elapsed;
    game->chat.chat_time += elapsed;
    uhd(game);
    other_world(game);
    handle_shoot(game, elapsed);
    select_map(game);
    init_mv(game);
    manage_colide(game);
    move_all(game);
    chat(game);
    manage_door(game, elapsed);
    attacking_ghost(game, elapsed);
    manage_animation(game);
    ghost_attack(game);
    kill_ghost(game);
    change_gun(game);
    if (game->other_world == 1)
        boss(game, elapsed);
}

int lose(game_t *game)
{
    if (sfSprite_getScale(game->hero.life).x < 0) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return 1;
        sfRenderWindow_drawSprite(game->window, game->over, NULL);
        sfRenderWindow_drawText(game->window, game->boss.end_msg, NULL);
    }
    return 0;
}

void my_rpg(void)
{
    game_t *game = malloc(sizeof(game_t));
    float elapsed;

    srand(42);
    init_game(game);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        elapsed = sfTime_asSeconds(sfClock_restart(game->game_clock));
        display_all(game);
        manage_events(game);
        if (game->step == GAME)
            manage_gameplay(game, elapsed);
        if (lose(game))
           break;
        sfRenderWindow_display(game->window);
    }
}
