/*
** EPITECH PROJECT, 2022
** solo stumper
** File description:
** solo stumper six
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int prtm(int num)
{
    if (num == 1)
        printf(" Bogey\n");
    if (num == 2)
	printf(" Double bogey\n");
    if (num == 3)
        printf(" Triple bogey\n");
    if (num > 3)
        printf(" +%d\n", num);
    return 0;
}

int prt(int num, int one)
{
    if (one == 1) {
        printf(" Hole-in-one!\n");
        return 0;
    }
    if (num == -4)
        printf(" Condor\n");
    if (num == -3)
        printf(" Albatros\n");
    if (num == -2)
        printf(" Eagle\n");
    if (num == -1)
        printf(" Birdie\n");
    if (num == 0)
        printf(" Par\n");
    return 0;
}

char *my_strtok(char *str,  int n)
{
    char *num = malloc(sizeof(char)*4);
    int count = 0;
    int save_i = 0;
    
    for (int i = 0;str[i] != '\0';i++) {
        if (count == n) {
            save_i = i;
            break;
        }
        if (str[i] == ',')
            count++;
    }
    count = 0;
    for (int i = save_i;str[i] != ',';i++) {
        num[count] = str[save_i];
        count++;
        if (str[i] == '\0')
            break;
    }
    return num;
}

void golf(char *par, char *strokes, int l)
{
    char *tok = malloc(sizeof(char)*3);
    char *tokb = NULL;
    int num = 0;
    int hole = 1;
    int pr = 0;
    int ss = 0;

    for (int i = 0; i != l+1;i++) {
        tok = my_strtok(par,hole-1);
        pr += atoi(tok);
        printf("Hole %d (Par %s):", hole, tok);
        tokb = my_strtok(strokes,hole-1);
        ss += atoi(tokb);
        num = atoi(tokb) - atoi(tok);
        prt(num, atoi(tokb));
        hole++;
    }
    printf("Total par: %d\n", pr);
    printf("Total strokes: %d\n", ss);
    if (pr-ss > 0)
        printf("Final score: +%d\n", pr-ss);
    else
        printf("Final score: %d\n", pr-ss);
}

int main(int argc, char **argv)
{
    int l = 0;

    if (argc != 3)
        return 84;
    for (int i = 0;argv[1][i] != '\0';i++)
        l = i;
            golf(argv[1], argv[2],l);
}
