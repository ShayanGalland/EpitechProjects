/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "functions.h"

char **load_environ(void)
{
    char **env;
    int environ_size = 0;
    int size = 0;

    for (;environ[environ_size] != NULL; environ_size++) {
    }
    environ_size += 2;
    env = malloc(sizeof(char*) * environ_size);
    for (int i = 0; environ[i] != NULL;i++) {
        size = my_strlen(environ[i]);
        env[i] = malloc(sizeof(char) * size);
        my_memcpy(environ[i], env[i], size);
    }
    return env;
}

int find_variable(const char* variable_name, char** env)
{
    int path_idx = -1;

    for (int i = 0;env[i] != NULL;i++) {
        if (my_strstr(env[i], variable_name) == env[i]) {
            path_idx = i;
            break;
        }
    }
    return path_idx;
}