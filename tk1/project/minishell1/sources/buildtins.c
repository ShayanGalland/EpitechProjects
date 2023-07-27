/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "functions.h"

void buildtin_cd(command_info_t *command_info, char **env)
{
    if (command_info->argc == 2)
        chdir(command_info->argv[1]);
    else {
        if (command_info->argc == 1)
            chdir(&env[find_variable("HOME=", env)][5]);
        else
            write(1, "cd: Too many arguments.\n", 19);
    }
}

void buildtin_exit(command_info_t *command_info)
{
    int return_code = 0;

    if (command_info->argc == 1 || command_info->argc == 2) {
        return_code = 0;
        if (command_info->argc == 2)
            return_code = my_getnbr(command_info->argv[1]);
        exit(return_code);
    }
}
/*
void buildtin_setenv(command_info_t *command_info, char ***env_ptr)
{
    char **env = *env_ptr;
    int i = 0;
    int size = 0;
    int idx_var = 0;

    if (command_info->argc == 3) {
        idx_var = find_variable(command_info->argv[1], env);
        if (idx_var != -1) {
            free(env[idx_var]);
            size = my_strlen(command_info->argv[1]) + 1 + my_strlen(command_info->argv[2]);
            env[idx_var] = malloc(sizeof(char)*size);
            my_memset(env[idx_var], 0, sizeof(char)*size);
            my_strcpy(env[idx_var], command_info->argv[1]);
            my_strcat(my_strcat(env[idx_var], "="), command_info->argv[2]);
        }
        else {
            for(;env[i] != NULL; i++)
                ;
            i += 1;
            env = my_realloc(env, sizeof(char*)*i, sizeof(char*)*(i+1));
            size = my_strlen(command_info->argv[1]) + 1 + my_strlen(command_info->argv[2]);
            env[i-1] = malloc(sizeof(char)*size);
            my_memset(env[i-1], 0, sizeof(char)*size);
            my_strcpy(env[i-1], command_info->argv[1]);
            my_strcat(my_strcat(env[i-1], "="), command_info->argv[2]);
            env[i] = NULL;
            *env_ptr = env;
        }
    }
    else
        buildtin_env(env);
}*/
void env_set_one(char **env, char ***env_ptr, command_info_t *cmd)
{
    int i = 0;
    int size = 0;
    int idx_var = 0;

    idx_var = find_variable(cmd->argv[1], env);
    if (idx_var != -1) {
        free(env[idx_var]);
        size = my_strlen(cmd->argv[1]) + 1;
        env[idx_var] = malloc(sizeof(char)*size);
        my_memset(env[idx_var], 0, sizeof(char)*size);
        my_strcpy(env[idx_var], cmd->argv[1]);
        my_strcat(env[idx_var], "=");
    }
    else {
        for (;env[i] != NULL; i++)
            ;
        i += 1;
        env = my_realloc(env, sizeof(char*)*i, sizeof(char*)*(i+1));
        env[i-1] = malloc(sizeof(char)*size);
        my_memset(env[i-1], 0, sizeof(char)*size);
        my_strcpy(env[i-1], cmd->argv[1]);
        my_strcat(env[i-1], "=");
        env[i] = NULL;
        *env_ptr = env;
    }
}

void env_set_two(char **env, char ***env_ptr, command_info_t *cmd)
{
    int i = 0;
    int size = 0;
    int idx_var = 0;

    idx_var = find_variable(cmd->argv[1], env);
    if (idx_var != -1) {
        free(env[idx_var]);
        size = my_strlen(cmd->argv[1]) + 1 + my_strlen(cmd->argv[2]);
        env[idx_var] = malloc(sizeof(char)*size);
        my_memset(env[idx_var], 0, sizeof(char)*size);
        my_strcpy(env[idx_var], cmd->argv[1]);
        my_strcat(my_strcat(env[idx_var], "="), cmd->argv[2]);
    }
    else {
        for (;env[i] != NULL; i++)
            ;
        i += 1;
        env = my_realloc(env, sizeof(char*)*i, sizeof(char*)*(i+1));
        size = my_strlen(cmd->argv[1]) + 1 + my_strlen(cmd->argv[2]);
        env[i-1] = malloc(sizeof(char)*size);
        my_memset(env[i-1], 0, sizeof(char)*size);
        my_strcpy(env[i-1], cmd->argv[1]);
        my_strcat(my_strcat(env[i-1], "="), cmd->argv[2]);
        env[i] = NULL;
        *env_ptr = env;
    }
}

void buildtin_setenv(command_info_t *command_info, char ***env_ptr)
{
    char **env = *env_ptr;

    if (command_info->argc > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return;
    }
    if (command_info->argc == 3)
        env_set_two(env, env_ptr, command_info);
    if (command_info->argc == 2) {
        env_set_one(env, env_ptr, command_info);
        return;
    }
    if (command_info->argc == 1) {
        buildtin_env(env);
        return;
    }
}

void buildtin_unsetenv(command_info_t *command_info, char ***env_ptr)
{
    char **env = *env_ptr;
    char **new_env = NULL;
    int idx_var = find_variable(command_info->argv[1], env);
    int size = 0;
    int new_env_idx = 0;

    if (idx_var != -1) {
        free(env[idx_var]);
        size = 0;
        for (;env[size] != NULL; size++)
            ;
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
        free(env);
        *env_ptr = new_env;
    }
}

void buildtin_env(char **env)
{
    int i = 0;

    while(env[i] != NULL) {
        my_putstr(env[i]);
        write(1, "\n" ,1);
        i++;
    }
}
