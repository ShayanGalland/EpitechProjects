/*
** EPITECH PROJECT, 2022
** getdata
** File description:
** getdata
*/

#include "include.h"

sfText *set_txt(char *text, int x, int y, float scale)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("asset/font/8_bit.ttf");

    sfText_setFont(txt, font);
    sfText_setString(txt, text);
    sfText_setScale(txt, (sfVector2f){scale, scale});
    sfText_setPosition(txt, (sfVector2f){x, y});
    return txt;
}

sfIntRect get_rects(int left, int top, int height, int width)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.height = height;
    rect.width = width;
    return rect;
}
