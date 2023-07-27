/*
** EPITECH PROJECT, 2021
** synthese
** File description:
** synthese project
*/

#include <stdio.h>
#include <stdlib.h>


int find_no_nul(char **array, int shift)
{
    int i = shift;

    while (array[i] == 0)
        i++;
    return i;
}

char **alphabetic_array(char **array, int shift)
{
    int bigger = find_no_nul(array, shift);
    int i = 1;
    int count = 0;

    while (array[i] != 0) {
        while (array[bigger][count] == array[i][count] &&
        array[bigger][count] != '\0' && array[i][0] != 127)
            count++;
        if (array[i][count] <= array[bigger][count] && array[i][0] != 127)
            bigger = i;
        i++;
        count = 0;
    }
    alphabetic_array()
    return bigger;
}


int main(int argc, char **argv)
{
    printf("%s", clean_dna(argv[1]));
}