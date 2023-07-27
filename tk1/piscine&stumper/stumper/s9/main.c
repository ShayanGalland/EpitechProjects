/*
** EPITECH PROJECT, 2022
** solo stumper
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int first_str(char *str)
{
    if (str[0] == 'A')
        return 4;
    if (str[0] == 'B')
        return 3;
    if (str[0] == 'C')
        return 2;
    if (str[0] == 'D')
        return 1;
    if (str[0] == 'E')
        return 0;
    return 0;
}

int main(int argc, char **argv)
{
    int l = 0;
    float res = 0;
    float ret = 0;
    int p = 0;
    
    if (argc == 1)
        return 84;
    for (int i = 1; i != argc; i++) {
        char *firstmm = malloc(sizeof(char)*5);
        l = first_str(argv[i]);
        for (int j = 2; argv[i][j] != '\0'; j++) {
            firstmm[p] = argv[i][j];
            p++;
        }
        res += (atoi(firstmm)*l);
        ret += atoi(firstmm);
        free(firstmm);
    }
    printf("%.2f\n", res/ret);
    return 0;
}
    
