/*
** EPITECH PROJECT, 2021
** my_print_digits
** File description:
** 
*/


int my_putchar(char c);

int my_print_digits(void)
{
    char nombre;
    nombre = 48;

    while(nombre <= 57) {
        my_putchar(nombre);
        nombre = nombre + 1;
    }
    
    return(0);
}
