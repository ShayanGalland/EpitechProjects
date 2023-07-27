/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** emacs
*/
#include "my_getnbrMP.c"

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    
    while(str[i] == '-' || str[i] == '+'){
        i++;}
    
    while(str[i] != '\0'){
        if(str[i] <= '0' || str[i] >= '9')
            break;
        if (str[i] <= '9' || str[i] >= '0'){
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';}
        i++;}
    
    if(my_getnbrMP(str) == '-'){
	nbr = nbr * -1;}
    
    if(my_strlen(str) >= 9){
        return(0);}
        return(nbr);
}
