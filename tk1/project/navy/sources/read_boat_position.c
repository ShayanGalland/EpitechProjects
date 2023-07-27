/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int read_boat_position(const char* boat_filepath, char** my_map){
    int fp = open(boat_filepath,O_RDONLY);
    int i = 0;
    char buffer[256];
    int bytes_read = 0;
    bytes_read = read(fp, buffer, 255);
    if(bytes_read == -1){
        close(fp);
        return 1;
    }
    if(!fp)
        return 1;
    buffer[bytes_read] = '\0';
    while(buffer[i] != '\0') {
        if (boat_pos(buffer, i, my_map) == 84)
            break;
        else
            i = boat_pos(buffer, i, my_map);
    }
    return 0;
}
