/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** y
*/
char *my_strcat(char *dest , char const *src)
{
    int i;
    int dest_len = strlen(dest);
    
    for (i = 0; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    
    return (dest);
}

