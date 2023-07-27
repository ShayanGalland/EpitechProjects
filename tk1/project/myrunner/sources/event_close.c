/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void event_close(sfRenderWindow *renderWindow)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(renderWindow, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(renderWindow);
    }

}