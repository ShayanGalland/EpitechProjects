/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** t
*/
char *my_strncpy(char *dest, char const *src, int n)
{
    int b = 0;

    while(b != n){
        dest[b] = src[b];
        b++;
    }
    return(dest);
}

