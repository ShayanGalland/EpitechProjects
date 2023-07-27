/*
** EPITECH PROJECT, 2021
** dd
** File description:
** dd
*/
#include "my_putstr.c"
#include "my_revstr.c"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *infin_add(char *str1, char *str2)
{
    int len1;
    int len2;
    int res = 0;
    int ret = 0;
    int i = 0;
    char *result;
    
    len1 = my_strlen(str1);
    len2 = my_strlen(str2);
    result = malloc(sizeof(char) * (len1 + 2));
    str1 = my_revstr(str1);
    str2 = my_revstr(str2);
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        res = (str1[i] - 48) + (str2[i] - 48) + ret;
        printf("%d", res);
        if(res >= 10 )
        {
            result[i] =  res % 10 + 48;
            ret = 1;
            i = i + 1;
            if (str1[i] == '\0' || str2[i] == '\0')
            {
                result[i] = ret + 48;
            }
        }
        if(res < 10)
        {
            res = res + ret;
            result[i] = (res + 48);
            ret = 0;
            i = i + 1;
            if(str1[i] == '\0' || str2[i] == '\0')
            {
                result[i] = ret + 48;
            }
        }
        result[i] = '\0';
    }
    my_revstr(result);
    my_putstr(result);
    return(result);
}
int main (int ac, char **av)
{
    ac = ac;
    printf("%d\n", infin_add(&av[1]));
    return (0);
}
