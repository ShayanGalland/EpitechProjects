/*
** EPITECH PROJECT, 2021
** my_print_revalpha
** File description:
** 
*/

int my_putchar(char c);

int my_print_revalpha(void)
{
    char alphabet;
    alphabet = 122;

    while(alphabet > 96) {
        my_putchar(alphabet);
        alphabet = alphabet - 1;
    }

    return(0);
}
