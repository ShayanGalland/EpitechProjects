/*
** EPITECH PROJECT, 2021
** rush2
** File description:
** no
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int b = 1;
    int c = 0;
    int occurence = 0;
  
    while(argv[b][c] != '\0'){
        if(argv[b][c] == argv[2][0]) {
            occurence = occurence + 1;
        }
        
        
        c = c + 1;
        
    }

    printf("%c:%d\n",argv[2][0],occurence);
    return (0);
}    
