/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _FUNCTIONS_H
    #define _FUNCTIONS_H
    #define INPUT_END 1
    #define OUTPUT_END 0
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include "struct.h"
    #include <sys/stat.h>
    #include <fcntl.h>

extern const char **environ;
char *line_zero(char *line);
void inf_gestion(command_info_t* command_info, int read, char ***env);
void buildtin_cd(command_info_t *command_info, char **env);
void buildtin_exit(command_info_t *command_info);
void buildtin_setenv(command_info_t *command_info, char ***env_ptr);
char *no_space(char *new_str, char *old_str);
char *delete_space(char *str);
void buildtin_unsetenv(command_info_t *command_info, char ***env);
void display_env(char **env);
int my_getnbr(char const *str);
void my_memcpy(const char *src, char *dst, size_t size);
void my_memset(char *dst, char v, size_t size);
void* my_realloc(void *ptr, size_t size_ptr, size_t new_size);
int my_strlen(char const *str);
int my_strcmp(const char *str1, const char *str2);
const char *my_strstr(const char *str, const char *token);
char *my_strcat(char *dst, const char *src);
void my_strcpy(char *dst, const char *src);
char **load_environ(void);
int find_variable(const char *variable_name, char **env);
void find_absolute_path(const char *command, char **env, char *absolute_path);
void exec_external_command(command_info_t *command_info, char **env);
void exec_command(command_info_t *command_info, char ***env);
void print_prompt(void);
void parse_inputs(char *line, command_info_t *command_info);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_putnbr(int nb);
char *my_strcat_aloc(char *str1, char *str2);
char *search_in_env(char **env, char *str);
char **mod_env(char **env, char *path, char *new);
int putstr_er(char const *str);
int is_same_str(const char *token, const char *str, int i, int token_len);
int is_delimiter(char *line, int i);
int count_sections(char *line);
int count_pipe_sections(char *line);
void exec_pipe_section(pipe_segment_t *pipe, char ***env);
int delim_colon(char *line, char ***env);
int exec_semicolonsection(semicolon_segment_t *semi_sec, char ***env);
int count_semi_secs(char *line);
void exec_pipe_section_2(pipe_segment_t *section_1, pipe_segment_t *section_2, char ***env);
void my_putchar_er(char c);
#endif
