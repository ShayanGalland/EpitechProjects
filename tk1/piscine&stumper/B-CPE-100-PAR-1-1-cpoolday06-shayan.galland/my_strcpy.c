/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** t
*/
char *my_strcpy(char *dest, char const *src)
{
    int b = 0;
    
    while(src[b] != '\0'){
        dest[b] = src[b];
        b++;
    }
    return(dest);
}
