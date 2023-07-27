/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"


void parse_inputs(char *line, command_info_t *command_info)
{
    char *token = strtok(line, " ");

    command_info->argc = 1;
    command_info->argv = malloc(sizeof(char*) * 1);
    command_info->argv[0] = token;
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token == NULL)
            break;
        command_info->argc++;
        command_info->argv = my_realloc(command_info->argv,
        sizeof(char*)*(command_info->argc-1), sizeof(char*)*command_info->argc);
        command_info->argv[command_info->argc-1] = token;
    }
    command_info->argv = my_realloc(command_info->argv,
    sizeof(char*)*command_info->argc, sizeof(char*)*(command_info->argc+1));
    command_info->argv[command_info->argc] = NULL;
}

void print_prompt(void)
{
    char *current_directory = NULL;

    current_directory = getcwd(NULL, 0);
    my_putstr(current_directory);
    write(1, "$ ", 2);
    free(current_directory);
}

void inf_gestion(command_info_t* command_info, int read, char ***env)
{
    for (int i = 0; command_info->line[i] != '\0'; i++) {
        if (command_info->line[i] == '\n')
            command_info->line[i] = '\0';
    }
    if (read > 1) {
        command_info->line = delete_space(command_info->line);
        parse_inputs(command_info->line, command_info);
        exec_command(command_info, env);
    }
    free(command_info->line);
}

int minishell(char ***env)
{
    size_t size = 0;
    char *line = NULL;
    int read = 0;
    int last_ret = 0;

    while (1) {
        if (isatty(stdin->_fileno))
            print_prompt();
        size = 0;
        line = NULL;
        read = getline(&line, &size, stdin);
        if(read == -1)
            break;
        if (line[0] == '\n')
            continue;
        if (line[0] == '\0' || line[0] == 0)
            break;
        last_ret = delim_colon(line, env);
        free(line);
    }

    return last_ret;
}

int main(void)
{
    char **env = NULL;
    char *dir = NULL;

    if (environ[0] == NULL) {
        dir = getcwd(NULL, 0);
        env = malloc(sizeof(char*)*4);
        env[0] = malloc(sizeof(char) * (my_strlen("PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin")+1));
        my_strcpy(env[0], "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin");
        env[1] = malloc(sizeof(char)*(my_strlen(dir)+5));
        env[1] = my_strcat_aloc("PWD=", dir);
        env[2] = malloc(sizeof(char)*(my_strlen(dir)+8));
        env[2] = my_strcat_aloc("OLDPWD=", dir);
        env[3] = NULL;
        free(dir);
    }
    else
        env = load_environ();
    return minishell(&env);
}
