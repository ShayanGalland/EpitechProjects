/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void wait_for_keypressed(sfRenderWindow *window)
{
    sfEvent event;
    int keyPressed = 0;
    while(!keyPressed){
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                keyPressed = 1;
            }
            if (event.type == sfEvtKeyPressed)
                keyPressed = 1;
        }
    }
}

void win(game_t *game_t, sfRenderWindow *window)
{
    sfText* text = sfText_create();
    sfText_setCharacterSize(text, 32);
    sfText_setFont(text, game_t->font);
    sfVector2f pos;
    pos.x = 200;
    pos.y = 200;
    sfText_setPosition(text, pos);
    sfText_setString(text, "WIN ! Press a key to quit");
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    wait_for_keypressed(window);
    sfRenderWindow_close(window);
}

void move_cars(game_t *game_t, float elapsed)
{
    sfVector2f offset;
    offset.x = -1*500*elapsed;
    offset.y = 0;
    for(int i = 0; i < 5; i++) {
        if(game_t->enemies[i].is_active == 1)
            sfSprite_move(game_t->enemies[i].sprite ,offset);
    }
}

void draw_en(float elapsed, sfRenderWindow *window, game_t *game_t)
{
    game_t->time_e += elapsed;
    if (game_t->time_e > game_t->fram_e) {
        game_t->fram_e += 1.0f;
        if (game_t->rd_mp[game_t->n] == '1') {
            for (int i = 0; i < 5; i++) {
                if (game_t->enemies[i].is_active == 0 ) {
                    sfSprite_setPosition(game_t->enemies[i].sprite, start_point(800,500));
                    game_t->enemies[i].is_active = 1;
                    break;
                }
            }
        }
        game_t->n += 1;
    }
    for(int i = 0; i < 5; i++){
        if (sfSprite_getPosition(game_t->enemies[i].sprite).x < -200 && game_t->enemies[i].is_active == 1)
            game_t->enemies[i].is_active = 0;
    }
    move_cars(game_t, elapsed);
    for(int i = 0; i < 5; i++){
        if (game_t->enemies[i].is_active == 1)
            sfRenderWindow_drawSprite(window, game_t->enemies[i].sprite, NULL); 
    }
    if (game_t->rd_mp[game_t->n] == '2')
        win(game_t, window);
}
