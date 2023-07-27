/*
** EPITECH PROJECT, 2021
** main
** File description:
** 
*/
#include <unistd.h>
#include "rush-1-1.c"
#include "rush-1-2.c"
#include "rush-1-3.c"
#include "rush-1-4.c"
#include "rush-1-5.c"

int my_strlen(char const *s);
char **rush3P1(char *str);
char **rush3P2(char *str);

int main(void)
{
    char buff[32000 + 1];
    int offset = 0;
    int len;
    
    while ((len = read(0 , buff + offset , 32001 - offset)) > 0) {
        offset = offset + len ;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84) ;
    rush3(buff) ;
    return (0) ;
}
