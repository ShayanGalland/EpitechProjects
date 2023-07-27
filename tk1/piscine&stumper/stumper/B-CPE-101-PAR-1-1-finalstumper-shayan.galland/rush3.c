/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** y
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "rush-1-1.c"
#include "rush-1-2.c"
#include "rush-1-3.c"
#include "rush-1-4.c"
#include "rush-1-5.c"

int my_strlen(char const *s)
{
    int i = 0;
    while(s[i] != '\0'){
	i++;
    }
    return(i);
}

char **rush3P1(char *str)
{
    int y = 0;
    int x = 0;
    int r = 0
        ;
    char **tabl = malloc(sizeof(char) * strlen(str));
    
    tablA[y][x] = str[r];
    
    while(tablA[y][x] != '\0'){
        while(tablA[y][x] != '\n'){
            if(tablA[0][x] == '-')
		return(rush-1-1.c);
            if(tablA[0][x] == '*')
		return(rush-1-2.c);
            if(tablA[0][x] == 'A')
		return(rush-1-3.c);
            r++;
            x++;
	}
        x = 0;
	y++;
    }
}

char **rush3P2(char *str)
{
    int l = 1;
    int n = 0;
    int p = 0;
    
    char **tabl = malloc(sizeof(char) * strlen(str));

    tablB[l][n] = str[p]
    
    while(tablB[l][n] != '\0'){
        while(tablB[l][n] != '\n'){
            if(tablB[l][0] == 'A')
                return(rush-1-4.c);
            if(tablB[l][n] == 'C')
                return(rush-1-5.c);
            p++;
            n++;
        }
        n = 0;
        l++;
    }
}
