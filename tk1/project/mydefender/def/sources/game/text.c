/*
** EPITECH PROJECT, 2022
** my_defender.c
** File description:
** my_defender.c
*/

#include "my_defender_game.h"

void my_itoa(char *buffer, int number)
{
   int divide = 0;
   int res;
   int l = 0;
   int digits_number;

   digits_number = number;
   while(digits_number != 0) {
        l++;
        digits_number /= 10;
    }
    for(divide = 0; divide < l; divide++) {
        res = number % 10;
        number = number / 10;
        buffer[l - (divide + 1)] = res + '0';
    }
    buffer[l] = '\0';
}

void prt_text_life(sfRenderWindow *window, map_t *map_t)
{
    char buffer[20];

    sfText_setFont(map_t->enemies_t->txt_heart, map_t->enemies_t->font_heart);
    sfText_setScale(map_t->enemies_t->txt_heart, start_point(2.5f, 2.5f));
    sfText_setPosition(map_t->enemies_t->txt_heart, start_point(1380, 20));
    my_itoa(&buffer[0], map_t->life_count);
    sfText_setString(map_t->enemies_t->txt_heart, buffer);
    sfRenderWindow_drawText(window, map_t->enemies_t->txt_heart, NULL);
}

void set_score(float elapsed, map_t *map_t)
{
    map_t->enemies_t->time_coin += elapsed;
    if (map_t->enemies_t->time_coin > 0.10) {
        map_t->coin_count += 1;
        map_t->enemies_t->time_coin -= 0.10;
    }
}

void prt_text_coin(sfRenderWindow *window, map_t *map_t)
{
    char buffer[20];

    sfText_setFont(map_t->enemies_t->txt_coin, map_t->enemies_t->font_coin);
    sfText_setScale(map_t->enemies_t->txt_coin, start_point(2.5f, 2.5f));
    sfText_setPosition(map_t->enemies_t->txt_coin, start_point(920, 20));
    my_itoa(&buffer[0], map_t->coin_count);
    sfText_setString(map_t->enemies_t->txt_coin, buffer);
    sfRenderWindow_drawText(window, map_t->enemies_t->txt_coin, NULL);
}

void prt_price(sfRenderWindow *window, map_t *map_t, int number, sfVector2f pos)
{
    char buffer[20];

    buffer[0] = '$';
    sfText_setFont(map_t->tour_t->price, map_t->tour_t->fprice);
    sfText_setScale(map_t->tour_t->price, start_point(2.0f, 2.0f));
    sfText_setPosition(map_t->tour_t->price, pos);
    my_itoa(&buffer[1], number);
    sfText_setString(map_t->tour_t->price, buffer);
    sfRenderWindow_drawText(window, map_t->tour_t->price, NULL);
}