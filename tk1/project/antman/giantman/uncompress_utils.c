/*                                                                              
** EPITECH PROJECT, 2022                                                        
** y                                                                            
** File description:                                                            
** y                                                                            
*/

#include "functions.h"

void parse_oneline(int*buffer_it, char* line_buffer, char* data_buffer, int data_buffer_length) 
{
    for(int i = 0; i < data_buffer_length; i++) {
        if(data_buffer[(*buffer_it)] != '\n') {
            line_buffer[i] = data_buffer[(*buffer_it)];
            (*buffer_it)++;
        } else {
            line_buffer[i] = '\0';
            (*buffer_it)++;
            break;
        }
    }
}

int find_char(char* str, char value)
{
    for(int i = 0;;i++) {
        if(str[i] == value)
            return i;
        if(str[i] == '\0')
            break;
    }
    return 0;
}
