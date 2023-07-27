/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

void set_path(char *token, char *absolute_path, const char *command)
{
    while (token != NULL) {
        my_memset(absolute_path, 0, 256);
        my_strcpy(absolute_path, token);
        my_strcat(my_strcat(absolute_path, "/"), command);
        if (access(absolute_path, F_OK) == 0)
            return;
        token = strtok(NULL, ":");
        if (token == NULL)
            return;
    }
}

void exec_prog(char *path_buffer, command_info_t *command_info, char **env)
{
    execve(path_buffer, command_info->argv, env);
    putstr_er(command_info->argv[0]);
    write(2, ": Command not found.\n", 21);
    exit(EXIT_FAILURE);
}

void find_absolute_path(const char *command, char **env, char *absolute_path)
{
    char *current_directory = getcwd(NULL, 0);
    char *var_path = NULL;
    int path_idx = 0;
    char *token = NULL;

    my_strcpy(absolute_path, current_directory);
    my_strcat(my_strcat(absolute_path , "/"), command);
    free(current_directory);
    if (access(absolute_path, F_OK) == 0 )
        return;
    path_idx = find_variable("PATH=", env);
    var_path = malloc(sizeof(char)*(my_strlen(&env[path_idx][5])+1));
    my_strcpy(var_path, &env[path_idx][5]);
    token = strtok(var_path, ":");
    set_path(token, absolute_path, command);
    free(var_path);
}

void exec_external_command(command_info_t *command_info, char **env)
{
    char path_buffer[256];
    int status = 0;
    int i = 0;
    pid_t pid = 0;

    if(!command_info->already_fork) {
        pid = fork();
    }

    my_memset(&path_buffer, 0, 256);
    if (access(command_info->argv[0], F_OK) == 0) {
        my_strcpy(path_buffer, command_info->argv[0]);
    } else
        find_absolute_path(command_info->argv[0], env, path_buffer);
    if (pid == 0)
        exec_prog(path_buffer, command_info, env);
    else {
        while (waitpid(pid, &status, WUNTRACED) == -1)
            ;
        command_info->status = WEXITSTATUS(status);
        if (WIFSIGNALED(status))
            i = 1;
        if (WTERMSIG(status) == SIGSEGV && i == 1) {
            write(2, "Segmentation fault (core dumped)\n", 33);
            signal(SIGSEGV, SIG_IGN);
        }
    }
}


void exec_command_2(command_info_t *command_info, char ***env){
    if (my_strcmp(command_info->argv[0], "cd") == 0 ||
    my_strcmp(command_info->argv[0], "chdir") == 0)
        return buildtin_cd(command_info, *env);
    if (my_strcmp(command_info->argv[0], "exit") == 0)
        return buildtin_exit(command_info);
    if (my_strcmp(command_info->argv[0], "setenv") == 0)
        return buildtin_setenv(command_info, env);
    if (my_strcmp(command_info->argv[0], "unsetenv") == 0)
        return buildtin_unsetenv(command_info, env);
    if (my_strcmp(command_info->argv[0], "env") == 0)
        return display_env(*env);
    return exec_external_command(command_info, *env);
}

void exec_command(command_info_t *command_info, char ***env)
{
    if(command_info->argc > 2) {
        for(int i = 0; command_info->argv[command_info->argc-2][i] != '\0'; i++) {
            int del = is_delimiter(command_info->argv[command_info->argc-2], i);
            if(del == 5 || del == 6) {
                int flags = 0;
                if(del == 5)
                    flags = O_WRONLY | O_APPEND | O_CREAT;
                else if(del == 6)
                    flags = O_TRUNC | O_RDWR | O_CREAT;

                int pid = 0;
                int file = open(command_info->argv[command_info->argc-1], flags, 0644);
                pid = fork();

                if (pid == 0) {
                    dup2(file, STDOUT_FILENO);
                    close(file);
                    
                    command_info->argv[command_info->argc-1] = NULL;
                    command_info->argv[command_info->argc-2] = NULL;
                    command_info->argc = command_info->argc - 2;

                    exec_command_2(command_info, env);
                    exit(0);
                }
                close(file);
                waitpid(pid, NULL, 0);
                break;
            }
        }
    } else {
        exec_command_2(command_info, env);
    }
}
