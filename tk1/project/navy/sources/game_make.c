/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int game_make(char **argv, int argc, int player_id)
{
    char **my_map = create_map();
    char **their_map = create_map();
    if(my_strcmp(argv[1], "-h") == 0) {
        print_man();
        return 0;
    }
    const char* boat_filepath = NULL;
    short otherplayer_pid = 0;
    if(argc == 2)
        boat_filepath = argv[1];
    else {
        otherplayer_pid = my_getnbr(argv[1]);
        boat_filepath = argv[2];
    }
    if(read_boat_position(boat_filepath, my_map) != 0)
        return 84;
    write(1, "my_pid: ", 9);
    my_putnbr(getpid());
    my_putchar('\n');
    con_pid(otherplayer_pid, player_id, my_map, their_map);
    return 0;
}