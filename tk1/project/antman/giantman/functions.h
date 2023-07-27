/*                                                                              
** EPITECH PROJECT, 2022                                                        
** y                                                                            
** File description:                                                            
** y                                                                            
*/

#ifndef _FUNCTIONS_H
    #define _FUNCTIONS_H
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <stdio.h>
    #define FILE_TYPE_LYRICS 1
    #define FILE_TYPE_HTML 2
    #define FILE_TYPE_P3PPM 3

int uncompress_file(char* file_path, int file_type);
int uncompress_lyrics(char* data_buffer, int data_buffer_length);
int uncompress_html(char* data_buffer, int data_buffer_length);
int uncompress_p3ppm(char* data_buffer, int data_buffer_length);
int my_getnbr(char const *str);
void my_memcpy(char* src, char* dst, size_t size);
void my_memset(char* dst, char v, size_t size);
void* my_realloc(void* ptr, size_t size_ptr, size_t new_size);
int my_strlen(char const *str);
int my_strcmp(const char* str1, const char* str2);
const char* my_strstr(const char* str, const char* token);
char* my_strcat(char *dst, const char *src);
void my_strcpy(char *dst, const char *src);
void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
void parse_oneline(int*buffer_it, char* line_buffer, char* data_buffer, int data_buffer_length);
int find_char(char* str, char value);
#endif
