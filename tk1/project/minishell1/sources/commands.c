/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "functions.h"

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
    while (token != NULL) {
        my_memset(absolute_path, 0, 256);
        my_strcpy(absolute_path, token);
        my_strcat(my_strcat(absolute_path, "/"), command);
        if (access(absolute_path, F_OK) == 0 )
            break;
        token = strtok(NULL, ":");
        if (token == NULL)
            break;
    }
    free(var_path);
}

void exec_external_command(command_info_t *command_info, char **env)
{
    char path_buffer[256];
    int status = 0;

    find_absolute_path(command_info->argv[0], env, path_buffer);
    pid_t pid = fork();
    if (pid == 0) {
        execve(path_buffer, command_info->argv, env);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else {
        status = 0;
        while (waitpid(pid, &status, WUNTRACED) == -1)
            ;
        command_info->status = WEXITSTATUS(status);
        if(WIFSIGNALED(status)) {
            if(WTERMSIG(status) == SIGSEGV)
                write(2, "Segmentation fault\n", 20);
        }
    }
}

void exec_command(command_info_t *command_info, char ***env)
{
    if (my_strcmp(command_info->argv[0], "cd") == 0)
        buildtin_cd(command_info, *env);
    else if (my_strcmp(command_info->argv[0], "exit") == 0)
        buildtin_exit(command_info);
    else if (my_strcmp(command_info->argv[0], "setenv") == 0)
        buildtin_setenv(command_info, env);
    else if (my_strcmp(command_info->argv[0], "unsetenv") == 0)
        buildtin_unsetenv(command_info, env);
    else if (my_strcmp(command_info->argv[0], "env") == 0)
        buildtin_env(*env);
    else
        exec_external_command(command_info, *env);
}


