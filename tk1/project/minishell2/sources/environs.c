/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

int find_variable(const char *variable_name, char **env)
{
    int path_idx = -1;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strstr(env[i], variable_name) == env[i]) {
            path_idx = i;
            break;
        }
    }
    return path_idx;
}

char **load_environ(void)
{
    char **env;
    int environ_size = 0;
    int size = 0;

    for (;environ[environ_size] != NULL; environ_size++) {
    }
    environ_size += 1;
    env = malloc(sizeof(char*) * environ_size);
    my_memset(env, NULL, sizeof(char*) * environ_size);
    for (int i = 0; environ[i] != NULL;i++) {
        size = my_strlen(environ[i]);
        env[i] = malloc(sizeof(char) * (size+1));
        my_memset(env[i], '\0', size+1);
        my_memcpy(environ[i], env[i], size);
    }
    return env;
}

char *search_in_env(char **env, char *str)
{
    int i = 0;
    int len = 0;
    char *result = NULL;
    int p = 0;

    while (env[i] != NULL) {
        i++;
        if (env[i] && my_strstr(env[i], str) != NULL) {
            len = my_strlen(env[i]) - my_strlen(str) + 1;
            break;
        }
    }
    if(len > 0){
        result = malloc(sizeof(char)*len);
        for (int n = my_strlen(str); n != my_strlen(env[i]); n++) {
            result[p] = env[i][n];
            p++;
        }
        
        result[len-1] = '\0';
        return result;
    } else {
        return NULL;
    }
    result[len-1] = '\0';
    return result;
}

char **mod_env(char **env, char *path, char *new)
{
    int idx_var = 0;

    idx_var = find_variable(path, env);
    if (idx_var != -1) {
        free(env[idx_var]);
        env[idx_var] = malloc(sizeof(char)*(my_strlen(new)+1));
        env[idx_var] = new;
    }
    return env;
}

void display_env(char **env)
{
    int i = 0;

    if (env == NULL)
        return;
    while (env[i] != NULL) {
        my_putstr(env[i]);
        write(1, "\n" ,1);
        i++;
    }
}
