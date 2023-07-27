/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _FUNCTIONS_H
    #define _FUNCTIONS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
struct command_info
{
    int argc;
    char **argv;
    int status;
};
typedef struct command_info command_info_t;
extern char **environ;
void buildtin_cd(command_info_t *command_info, char **env);
void buildtin_exit(command_info_t *command_info);
void buildtin_setenv(command_info_t *command_info, char ***env);
void buildtin_unsetenv(command_info_t *command_info, char ***env);
void buildtin_env(char **env);
int my_getnbr(char const *str);
void my_memcpy(char *src, char *dst, size_t size);
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
void ignoreSignal(int sig);
void print_prompt(void);
void parse_inputs(char *line, command_info_t *command_info);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_putnbr(int nb);
#endif