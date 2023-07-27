/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void my_itoa(char *buffer, int number) {
   int divide = 0;
   int res;
   int  l = 0;
   int  digits_number;
   digits_number = number;
   while(digits_number != 0) {
     l++;
     digits_number /= 10;
   }
   for(divide = 0; divide < l; divide++) {
     res = number % 10;
     number= number/10;
     buffer[l - (divide + 1)] = res + '0';
   }
   buffer[l] = '\0';
}

void score(sfRenderWindow *renderWindow, game_t *game_t)
{
    sfText_setFont(game_t->score_text, game_t->font);
    sfVector2f pos;
    pos.x = 25;
    pos.y = 25;
    sfText_setPosition(game_t->score_text, pos);
    char buffer[20];
    buffer[0] = 'S';
    buffer[1] = 'c';
    buffer[2] = 'o';
    buffer[3] = 'r';
    buffer[4] = 'e';
    buffer[5] = ':';
    buffer[6] = ' ';
    my_itoa(&buffer[7], game_t->score);
    sfText_setString(game_t->score_text, buffer);
    sfRenderWindow_drawText(renderWindow, game_t->score_text, NULL);
}

int main(int argc, char **argv)
{
    game_t *game_t = game_stat();
    back_t *back_t = back_stat();
    int X = 800;
    int Y = 600;
    int resolution = 32;
    sfRenderWindow *renderWindow = create_render_window(X, Y, resolution);
    set_pos(back_t);
    if (argc == 2) {
        help(argv ,argc);
        enemies(argv, game_t);
    }
    float secondPass = 0.f;
    while (sfRenderWindow_isOpen(renderWindow)) {
        float elapsed = sfTime_asSeconds(sfClock_restart(game_t->game_clock));
        secondPass += elapsed;
        if(secondPass > 0.25) {
            game_t->score += 1;
            secondPass -= 0.25;
        }
        sfRenderWindow_display(renderWindow);
        parallax(renderWindow, elapsed, back_t, game_t);
        score(renderWindow, game_t);
        hero(elapsed, renderWindow, game_t);
        draw_en(elapsed, renderWindow, game_t);
    }
    sfRenderWindow_destroy(renderWindow);
    return 0;
}
