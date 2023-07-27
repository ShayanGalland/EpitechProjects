/*
** EPITECH PROJECT, 2021
** my_getnbrMP
** File description:
** y
*/
#include "my_strlen.c"

int my_getnbrMP(char const *str)
{
    int	capt = 0;
    int moins = 0;
    
    while(str[capt] != '\0'){
        if(str[capt] != '+' && str[capt] != '-'){
            capt++;
        }        
        if(str[capt] == '-'){
            moins++;
        }
        capt++;
    }
    
    if(moins % 2 == 0){
        
        return('+');
    }
    else
        return('-');
}
