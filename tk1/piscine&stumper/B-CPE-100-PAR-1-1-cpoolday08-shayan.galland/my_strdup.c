/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** y
*/
char *my_strdup(char const *src)
{
    char *dest;
    int i;
    
    dest = malloc(sizeof(char) * my_strlen(src));
    i = 0;
    while(i < my_strlen(src)){
    dest[i] = src[i];
    i++;
    }
    return(dest);
}
