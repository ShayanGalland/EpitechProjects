/*
** EPITECH PROJECT, 2022
** le
** File description:
** prj
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char* str)
{
    int i=0;
    while (str[i] != '\0')
        i++;
    return i;
}

int main(int argc, char **argv)
{
    char *str=argv[1];
    char *long_str=argv[2];
    int l=0;
    int occ=0;
    argc=argc;
    
    if (argc > 3)
        return 84;
    for (int i = 0; i != (my_strlen(long_str)-my_strlen(str))+1; i++) {
        for (int n = 0; n != my_strlen(str); n++) {
            if (str[n] == long_str[n+l])
                occ++;
            if (occ == my_strlen(str)) {
                write (1, "0\n" , 2);
                return 0;
            }
        }
        occ = 0;
        l++;
    }
    write(1, "1\n" , 2);
    return 0;
}
