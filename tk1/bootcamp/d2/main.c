/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include "iterative_factorial.c"
#include "recursive_power.c"
#include "my_strcpy.c"
#include "is_prime_number.c"
#include "my_strncmp.c"
#include "my_strstr.c"
#include "my_strupcase.c"

int main ()
{
    printf("recursive_power :%d\n",recursive_power(5, 4));
    printf("is_prime_number :%d\n",is_prime_number(15));
    printf("iterative_factorial :%d\n",iterative_factorial(4));
    char *test = strdup("bonjour je mange");
    char *test2 = strdup("du poisson");
    printf("my_strcpy :%s\n",my_strcpy(test,test2));
    char *test3 = strdup("bonjaur je mange");
    char *test4 = strdup("du peisson");
    printf("my_strncmp :%d\n",my_strncmp(test3,test4,5));
    char *test5 = strdup("je mange du poisson");
    char *test6 = strdup("poisson");
    printf("my_strstr :%s\n",my_strstr(test5,test6));
    char *test7 = strdup("je mange du poisson");
    printf("my_strupcase :%s\n","je lmange du poisson");
    return 0;
}
