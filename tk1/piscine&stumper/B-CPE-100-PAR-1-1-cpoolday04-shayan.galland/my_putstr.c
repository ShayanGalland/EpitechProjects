/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** 
*/

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != \0)
        my_putchar(str);
}

int main(void)
{
    int str;
    
    my_putstr(str);

    my_putchar(str);

    return(0);
}
