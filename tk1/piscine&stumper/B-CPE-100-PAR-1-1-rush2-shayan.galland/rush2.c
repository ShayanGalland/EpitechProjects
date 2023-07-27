/*
** EPITECH PROJECT, 2021
** step
** File description:
** no
*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Amy_putchar(char c)
{
    write(1, &c, 1);
}

int Amy_put_nbr(int nb)
{
    if (nb < 0){
        Amy_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
        Amy_put_nbr(nb/10);
        Amy_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        Amy_putchar(nb + '0');
    return (0);
}


int main(int argc, char **argv)
{
    int b = 1;
    int c = 0;
    int occurence = 0;
    int n = 2;
    int z = 0;

    while(n < argc)
    {
        if(argc == 1 || argv == 0){
            return (0);
        }
        while(argv[b][c] != '\0'){
            
            if(argv[n][0] <= '9' && argv[n][0] >= '0')
                return (84);
            

            if(argv[n][0] < 'A' || argv[n][0] > 'z')
		return(84);


                if(argv[n][0] < 'a' && argv[n][0] > 'Z')
                    return(84);
                
            
                    if((argv[b][c] == argv[n][0]) || (argv[b][c] == argv[n][0] + 32) ||( argv[b][c] == argv[n][0] - 32)) {
                        occurence = occurence + 1;
                    }
                    c = c + 1;
                }
                c = 0;
                Amy_putchar(argv[n][0]);
                Amy_putchar(':');
                Amy_put_nbr(occurence);
                n++;
                occurence = z;
                Amy_putchar('\n');
            }
            return(0);
        }
