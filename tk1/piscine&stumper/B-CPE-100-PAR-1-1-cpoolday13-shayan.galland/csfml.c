/*
** EPITECH PROJECT, 2021
** csfml.c
** File description:
** y
*/
#include <SFML/Graphics.h>

int main(int argc, char **argv)
{
    sfRenderWindow* window;
    sfColor color = sfColor_fromRGB(255, 255, 255);
    sfVideoMode mode = {800, 600, 32};
    window = sfRenderWindow_create(mode, "fenetre", sfResize | sfClose, NULL);

    if(window == 0)
        return -1;

    while(sfRenderWindow_isOpen(window)) {
        sfEvent* event;
        while (sfRenderWindow_pollEvent(window, event))
        {
            // Close window: exit
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        



        
        sfRenderWindow_clear(window, color);
        sfRenderWindow_display(window);
    }
    
    return 0;
}
