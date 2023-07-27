/*
** EPITECH PROJECT, 2021
** my_print_alpha
** File description:
** 
*/

int my_putchar(char c);

int  my_print_alpha(void)
{
    char alphabet;
    alphabet = 97;
        
    while(alphabet <  123) {
    my_putchar(alphabet);
    alphabet = alphabet + 1;
    }

    return(0);
}

