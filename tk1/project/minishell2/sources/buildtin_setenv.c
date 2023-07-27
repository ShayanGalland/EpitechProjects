/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

void in_env_one(char **env, int idx_var, command_info_t *cmd)
{
    int size = 0;

    free(env[idx_var]);
    size = my_strlen(cmd->argv[1]) + 1;
    env[idx_var] = malloc(sizeof(char)*size);
    my_memset(env[idx_var], 0, sizeof(char)*size);
    my_strcpy(env[idx_var], cmd->argv[1]);
    my_strcat(env[idx_var], "=");
}

void env_set_one(char **env, char ***env_ptr, command_info_t *cmd)
{
    int i = 0;
    int size = 0;
    int idx_var = 0;

    idx_var = find_variable(cmd->argv[1], env);
    if (idx_var != -1)
        in_env_one(env, idx_var, cmd);
    else {
        for (;env[i] != NULL; i++)
            ;
        i += 1;
        env = my_realloc(env, sizeof(char*)*i, sizeof(char*)*(i+1));
        size = my_strlen(cmd->argv[1]) + 2;
        env[i-1] = malloc(sizeof(char)*size);
        my_memset(env[i-1], 0, sizeof(char)*size);
        my_strcpy(env[i-1], cmd->argv[1]);
        my_strcat(env[i-1], "=");
        env[i-1][size-1] = '\0';
        env[i] = NULL;
        *env_ptr = env;
    }
}

void in_env_two(char **env, int idx_var, command_info_t *cmd)
{
    int size = 0;

    free(env[idx_var]);
    size = my_strlen(cmd->argv[1]) + 1 + my_strlen(cmd->argv[2]) + 1;
    env[idx_var] = malloc(sizeof(char)*size);
    my_memset(env[idx_var], 0, sizeof(char)*size);
    my_strcpy(env[idx_var], cmd->argv[1]);
    my_strcat(my_strcat(env[idx_var], "="), cmd->argv[2]);
    env[idx_var][size-1] = '\0';
}

void env_set_two(char **env, char ***env_ptr, command_info_t *cmd)
{
    int i = 0;
    int size = 0;
    int idx_var = 0;

    idx_var = find_variable(cmd->argv[1], env);
    if (idx_var != -1)
        in_env_two(env, idx_var, cmd);
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

int check_char(char c, char *str, int j)
{
    int u = 0;

    if (j == 0) {
        if (c == '!' || c == '@' || c == ',' || c == '?' || c == ':'
        || c == '-' || c == '=' || c == '+' || (c >= 48 && c <= 57)) {
            write(2, "setenv: Variable name must begin with a letter.\n" , 48);
            return 1;
        }
    }
    if (c == '!' || c == '@' || c == ',' || c == '?' || c == ':'
    || c == '-' || c == '=' || c == '+') {
        write(2, "setenv: Variable name must contain alphanumeric characters.\n" , 60);
        return 1;
    }
    if (c == '$') {
        for (int i = 0; str[i] != '$'; i++)
            my_putchar_er(str[i]);
        write(2, ": Undefined variable.\n", 22);
        return 1;
    }
    return 0;

}

int check_err(char **argv)
{
    int r = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            r = check_char(argv[i][j], argv[i], j);
        }
        if (r == 1)
            return 1;
    }
    return 0;
}

void buildtin_setenv(command_info_t *command_info, char ***env_ptr)
{
    char **env = *env_ptr;

    if (command_info->argc > 1) {
        if (check_err(command_info->argv))
            return;
    }
    if (command_info->argc == 2 && env != NULL)
        env_set_one(env, env_ptr, command_info);
    if (command_info->argc == 1 && env != NULL)
        display_env(env);
    if (command_info->argc == 3 && env != NULL)
        env_set_two(env, env_ptr, command_info);
    if (command_info->argc > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
    }
    return;
}