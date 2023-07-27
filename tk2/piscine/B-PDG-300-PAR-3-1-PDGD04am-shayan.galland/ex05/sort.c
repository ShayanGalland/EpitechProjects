/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "functions.h"

static int test_comp(const void *a, const void *b)
{
    return (strcmp (*( char **)a, *(char **)b));
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort_int_array(int *array , size_t nmemb)
{
    qsort(array, nmemb, sizeof(int), compare);
}

void rm_at_idx(int **array, int idx, size_t nmemb)
{
    int *dest;
    int j = 0;

    dest = malloc(sizeof(int) * nmemb);
    for (size_t i = 0; i < nmemb; i++) {
        if (i == idx)
            i++;

        dest[j] = *array[i];
        j++;

    }
    *array = dest;
}

size_t uniq_int_array(int *array , size_t nmemb)
{
    int idx = 0;

    for (size_t i = 0; i < nmemb; i++)
    {
        if (array[idx] == array[i] && idx != i)
            rm_at_idx(&array, i, nmemb);
    }
}





static void test_disp(const void *str)
{
    printf(" %s", *(char **) str);
}

int main(int argc , const char **argv)
{
    size_t nmemb;
    nmemb = 10;
    int *temp = NULL;
    temp = malloc(sizeof(int) * nmemb);
    temp[0] = 10;
    temp[1] = 2;
    temp[2] = 8;
    temp[3] = 25;
    temp[4] = 26;
    temp[5] = 29;
    temp[6] = 2;
    temp[7] = 0;
    temp[8] = 1;
    temp[9] = 88;
    //sort_int_array(temp, nmemb);
    rm_at_idx(&temp, 2, nmemb);
    for (int i = 0; i < nmemb; i++)
    {
        printf("%d\n", temp[i]);
    }




    //printf("argv:");
    //disp_array(argv , argc , sizeof (*argv), &test_disp);
    //printf("\n");
    //argc = uniq_array(argv , argc , sizeof (*argv), &test_comp);
    //printf("uniq:");
    //disp_array(argv , argc , sizeof (*argv), &test_disp);
    //printf("\n");
    //sort_array(argv , argc , sizeof (*argv), &test_comp);
    //printf("sort:");
    //disp_array(argv , argc , sizeof (*argv), &test_disp);
    //printf("\n");
    return (0);
}