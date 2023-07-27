/*
** EPITECH PROJECT, 2022
** my_defender.c
** File description:
** my_defender.c
*/

#include "my_defender_game.h"
#include "my_defender.h"

sfSound *inite(defender_state_t *defender_state);

sfSprite *init_sprite_pause(char *filename) {
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile
    (filename, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

unsigned int generate_random_number(int min, int max)
{
    int result  = rand() % ((max + 1) - min) + min;
    return result;
}

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *mySprite = sfSprite_create();
    sfSprite_setTexture(mySprite, texture, 0);
    return mySprite;
}

sfRenderWindow *create_window(sfRenderWindow *w, char *title)
{
    sfVideoMode video_mode = {1920, 1080, 64};
    w = sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    return (w);
}

int gameplay(game_t *d, map_t *map_t, float elapsed)
{
    map_one(d, map_t, elapsed);
    putpls_o(d, map_t);
    prt_tur(d, map_t);
    mv_turs(d, map_t);
    prt_text_life(d->window, map_t);
    prt_text_coin(d->window, map_t);
    set_score(elapsed, map_t);
    tur_param(d, map_t, elapsed);
    prt_price(d->window, map_t, 60, start_point(170, 200));
    prt_price(d->window, map_t, 80, start_point(170, 425));
    prt_price(d->window, map_t, 100, start_point(170, 675));
    prt_price(d->window, map_t, 200, start_point(170, 900));
    if (map_t->life_count == 0)
        return 0;
    return 1;
}

int my_defender(map_t *map_t, sfWindow *window)
{
    game_t d;
    int pause = 0;
    sfSprite *sprite_pasue = init_sprite_pause("asset/background/pause.png");
    sfSprite *sprite_transparencies = init_sprite_pause
    ("asset/background/transparencies.png");
    sfColor clor_sprite_transprencies = {255, 255, 255, 1};

    d.game_clock = sfClock_create();
    d.window = window;
    set_all_pos(map_t, &d);
    sfSprite_setColor(sprite_transparencies, clor_sprite_transprencies);
    while (sfRenderWindow_isOpen(d.window)) {
        sfRenderWindow_setFramerateLimit(d.window, 60);
        if (pause == 0) {
            float elapsed = sfTime_asSeconds(sfClock_restart(d.game_clock));
            if (!gameplay(&d, map_t, elapsed))
                break;
            sfRenderWindow_display(d.window);
            while (sfRenderWindow_pollEvent(d.window, &d.event)) {
                analyse_events(&d, map_t);
                if (d.event.type == sfEvtKeyPressed)
                    if (d.event.key.code == sfKeyEscape) {
                        pause = 1;
                    }
            }
        } else {
            sfRenderWindow_drawSprite(d.window, sprite_transparencies, NULL);
            sfRenderWindow_drawSprite(d.window, sprite_pasue, NULL);
            while (sfRenderWindow_pollEvent(d.window, &d.event)){
                sfClock_restart(d.game_clock);
                analyse_events(&d, map_t);
                if (d.event.type == sfEvtKeyPressed)
                    if (d.event.key.code == sfKeyEscape)
                        pause = 0;
            }
            sfRenderWindow_display(d.window);
        }
    }
    return 0;
}
