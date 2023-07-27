/*
** EPITECH PROJECT, 2021
** test
** File description:
** 
*/

int my_compute_factorial_it(int nb)
{
    int a = 1;
    int b = 1;
    int c = 1;
    int d = 1;
    
    if(nb == 0)
        return(0);
    if(nb == 1)
        return(0);
    
    while(b != nb){
        b = b + 1;
        c = b * a;
        a = a + 1;
        d = c * (a + 1);
    }
    
    return(d);
}
