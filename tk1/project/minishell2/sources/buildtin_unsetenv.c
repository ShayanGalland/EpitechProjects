/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

char **reset_env(int size, int idx_var, char **env)
{
    int new_env_idx = 0;
    char **new_env = NULL;

    size += 1;
    new_env = malloc(sizeof(char*)*(size-1));
    new_env_idx = 0;
    for (int i = 0; env[i] != NULL; i++) {
        if (i != idx_var) {
            new_env[new_env_idx] = env[i];
            new_env_idx++;
        }
    }
    new_env[size-2] = NULL;
    return new_env;
}

void buildtin_unsetenv(command_info_t *command_info, char ***env_ptr)
{
    char **env = *env_ptr;
    int idx_var = 0;
    int size = 0;

    if (command_info->argc == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return;
    }
    idx_var = find_variable(command_info->argv[1], env);
    if (idx_var != -1) {
        free(env[idx_var]);
        for ( ;env[size] != NULL; size++);
        *env_ptr = reset_env(size, idx_var, env);
        free(env);
    }
}
