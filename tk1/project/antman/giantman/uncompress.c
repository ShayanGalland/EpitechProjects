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

int uncompress_lyrics(char* data_buffer, int data_buffer_length)
{
    for(int i = 0; i < data_buffer_length;i++)
        my_putchar(data_buffer[i]);
    return 0;
}

int uncompress_html(char* data_buffer, int data_buffer_length)
{
    for(int i = 0; i < data_buffer_length;i++)
        my_putchar(data_buffer[i]);
    return 0;
}

int uncompress_p3ppm(char* data_buffer, int data_buffer_length)
{
    char line_buffer[256];
    my_memset(line_buffer, 0, 256);
    int buffer_it = 0;
    while(buffer_it < data_buffer_length) {   
        parse_oneline(&buffer_it, line_buffer, data_buffer, data_buffer_length);
        int idx = 0;
        if(idx = find_char(line_buffer, '@')) {
            line_buffer[idx] = '\0';
            int reference = my_getnbr(&line_buffer[idx+1]);
            for(int i = 0; i < reference; i++){
                my_putstr(line_buffer);
                my_putchar('\n');
            }
        } 
        else {
            my_putstr(line_buffer);
            my_putchar('\n');
        }
    }
}

int uncompress_file(char* file_path, int file_type)
{
    char * data_buffer = NULL;
    int data_buffer_length = -1;
    int return_code = open_and_read_file(file_path, &data_buffer, &data_buffer_length);
    
    if(return_code != 0)
        return return_code;
    switch(file_type) {
        case FILE_TYPE_LYRICS:
            return_code = uncompress_lyrics(data_buffer, data_buffer_length);
        break;
        case FILE_TYPE_HTML:
            return_code = uncompress_html(data_buffer, data_buffer_length);
        break;
        case FILE_TYPE_P3PPM:
            return_code = uncompress_p3ppm(data_buffer, data_buffer_length);
        break;
    }
    free(data_buffer);
    return return_code;
}
