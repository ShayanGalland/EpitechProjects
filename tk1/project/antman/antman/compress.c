/*                                                                              
** EPITECH PROJECT, 2022                                                        
** y                                                                            
** File description:                                                            
** y                                                                            
*/

#include "functions.h"

int compress_lyrics(char* data_buffer, int data_buffer_length)
{
    for(int i = 0; i < data_buffer_length;i++)
      my_putchar(data_buffer[i]);
    return 0;
}

int compress_html(char* data_buffer, int data_buffer_length)
{
    for(int i = 0; i < data_buffer_length;i++)
        my_putchar(data_buffer[i]);
    return 0;
}

int compress_p3ppm(char* data_buffer, int data_buffer_length)
{
    int count_reference = 0;
    char prev_line_buffer[256];
    char line_buffer[256];
    int buffer_it = 0;

    my_memset(prev_line_buffer, 0, 256);
    my_memset(line_buffer, 0, 256);
    while (buffer_it < data_buffer_length) {
        parse_oneline(&buffer_it, line_buffer, data_buffer, data_buffer_length);
        if (prev_line_buffer[0] == 0) {
            my_memcpy(line_buffer, prev_line_buffer, 256);
            count_reference++;
            continue;
        }
        if (my_strcmp(line_buffer, prev_line_buffer) == 0) {
            count_reference++;
            continue;
        }
        else
            prt(count_reference, line_buffer, prev_line_buffer);
        my_memcpy(line_buffer, prev_line_buffer, 256);
        count_reference = 1;
    }
    prt(count_reference, line_buffer, prev_line_buffer);
    return 0;
}

int compress_file(char* file_path, int file_type)
{
    char * data_buffer = NULL;
    int data_buffer_length = -1;
    int return_code = open_and_read_file(file_path, &data_buffer, &data_buffer_length);

    if(return_code != 0)
        return return_code;
    switch(file_type) {
        case FILE_TYPE_LYRICS:
            return_code = compress_lyrics(data_buffer, data_buffer_length);
        break;
        case FILE_TYPE_HTML:
            return_code = compress_html(data_buffer, data_buffer_length);
        break;
        case FILE_TYPE_P3PPM:
            return_code = compress_p3ppm(data_buffer, data_buffer_length);
        break;
    }
    free(data_buffer);
    return return_code;
}
