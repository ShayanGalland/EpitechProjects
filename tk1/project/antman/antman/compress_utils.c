/*                                                                              
** EPITECH PROJECT, 2022                                                        
** y                                                                            
** File description:                                                            
** y                                                                            
*/

#include "functions.h"

int open_and_read_file(char* file_path, char** data_buffer, int* data_buffer_length)
{
    struct stat stat_data;
    stat(file_path, &stat_data);
    *data_buffer_length = stat_data.st_size;
    *data_buffer = malloc(sizeof(char)* (*data_buffer_length));
    if(!*data_buffer)
        return 84;
    int fd = open(file_path, O_RDONLY);
    if(!fd)
        return 84;
    if(read(fd, *data_buffer, *data_buffer_length)  == -1) {
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

void parse_oneline(int*buffer_it, char* line_buffer, char* data_buffer, int data_buffer_length) 
{
    for (int i = 0; i < data_buffer_length; i++) {
        if (data_buffer[(*buffer_it)] != '\n') {
            line_buffer[i] = data_buffer[(*buffer_it)];
            (*buffer_it)++;
        } 
        else {
            line_buffer[i] = '\0';
            (*buffer_it)++;
            break;
        }
    }
}

void prt(int count_reference, char *line_buffer, char *prev_line_buffer)
{
    if (count_reference < 3) {
        for(int i = 0; i < count_reference; i++) {
            my_putstr(prev_line_buffer);
            my_putchar('\n');
        }
    } 
    else {
        my_putstr(prev_line_buffer);
        my_putchar('@');
        my_putnbr(count_reference);
        my_putchar('\n');
    }
}
