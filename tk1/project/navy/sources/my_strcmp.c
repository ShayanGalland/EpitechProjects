/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "fonctions.h"

int my_strcmp(const char* str1, const char* str2) {
    int str1_size = my_strlen(str1);
    int str2_size = my_strlen(str2);

    if(str1_size != str2_size)
        return -1;
    
    int i=0;
    while(i < str1_size) {
        if(str1[i] != str2[i])
            return -1;

        i++;
    }

    return 0;
}
