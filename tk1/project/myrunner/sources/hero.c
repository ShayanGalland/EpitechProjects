/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void gravity(float elapsed, game_t *game_t)
{
    sfVector2f offset;
    game_t->hero_vlc.y -= elapsed*1000;
    offset.x = 0;
    offset.y = game_t->hero_vlc.y*-elapsed;
    sfSprite_move(game_t->hero_spr, offset);
    sfVector2f capt = sfSprite_getPosition(game_t->hero_spr);
    if (capt.y >= 400) {
        game_t->hero_vlc.y = 0;
        capt.y = 400;
        sfSprite_setPosition(game_t->hero_spr, capt);
    }
}


int check_collision(sfSprite* hero, sfSprite* ennemy) {

    sfFloatRect rect_hero = sfSprite_getGlobalBounds(hero);
    sfFloatRect rect_ennemy = sfSprite_getGlobalBounds(ennemy);
    sfFloatRect intersection;
    sfFloatRect_intersects(&rect_hero, &rect_ennemy, &intersection);
    if(intersection.width > 40 || intersection.height > 40)
        return 1;
    return 0;
}

void game_over(game_t *game_t, sfRenderWindow *window)
{
    sfText* text = sfText_create();
    sfText_setCharacterSize(text, 32);
    sfText_setFont(text, game_t->font);
    sfVector2f pos;
    pos.x = 200;
    pos.y = 200;
    sfText_setPosition(text, pos);
    sfText_setString(text, "GAME OVER ! Press a key to quit");
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    wait_for_keypressed(window);
    sfRenderWindow_destroy(window);
}

void hero (float elapsed, sfRenderWindow *renderWindow, game_t *game_t)
{
    sfEvent event;
    create_and_anim(elapsed, game_t);
    gravity(elapsed, game_t);
    while (sfRenderWindow_pollEvent(renderWindow, &event)) {
        if (event.type == sfEvtClosed)
                sfRenderWindow_close(renderWindow);
        if (event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeySpace)) {
                sfVector2f capt = sfSprite_getPosition(game_t->hero_spr);
                if (capt.y >= 400) {
                    game_t->hero_vlc.y += 600;
                    sfSound_play(game_t->jump_sound);
                }
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        if(game_t->enemies[i].is_active == 1 && check_collision(game_t->hero_spr, game_t->enemies[i].sprite))
            game_over(game_t, renderWindow);
    }
    sfRenderWindow_drawSprite(renderWindow, game_t->hero_spr, NULL);
}
