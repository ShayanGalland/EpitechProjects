/*
** EPITECH PROJECT, 2021
** tools
** File description:
** help
*/

#include "my.h"

int help(int ac, char **av)
{
    if (ac != 2)
        return 0;
    if (my_strcmp(av[1], "-h") != 0 && my_strcmp(av[1], "--help") != 0)
        return 0;
    my_printf("USAGE: ./tetris [options]\nOptions:\n\t-h/--help\t\tDisplay ");
    my_printf("this page\n\t-L --level={NUM}\tStart Tetris at level NUM (de");
    my_printf("f : 1)\n\t-l --key-left={K}\tMove the tetrimino LEFT using t");
    my_printf("he K key (def: left arrow)\n\t-r --key-right={K}\tMove the t");
    my_printf("etrimino RIGHT using the K key (def: right arrow)\n\t-t --ke");
    my_printf("y-turn={K}\tTURN the tetrimino clockwise 90d using the K key");
    my_printf(" (def: top arrow)\n\t-d --key-drop={K}\tDROP the tetrimino u");
    my_printf("sing the K key (def: down arrow)\n\t-q --key-quit={K}\tQUIT ");
    my_printf("the game using the K key (def: 'q’ key)\n\t-p --key-pause={K");
    my_printf("}\tPAUSE/RESTART the game using the K key (def: space bar)\n");
    my_printf("\t--map-size={row,col}\tSet the numbers of rows and columns ");
    my_printf("of the map (def: 20,10)\n\t-w --without-next\tHide next tetr");
    my_printf("imino (def: false)\n\t-D --debug\t\tDebug mode (def: false)");
    my_printf("\n");
    return 1;
}
