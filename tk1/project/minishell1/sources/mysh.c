/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "functions.h"

void parse_inputs(char* line, command_info_t* command_info)
{
    char *token = strtok(line, " ");

    command_info->argc = 1;
    command_info->argv = malloc(sizeof(char*) * 1);
    command_info->argv[0] = token;
    while(token != NULL) {
        token = strtok(NULL, " ");
        if(token == NULL)
            break;
        command_info->argc++;
        command_info->argv = my_realloc(command_info->argv, sizeof(char*)*command_info->argc-1, sizeof(char*)*command_info->argc);
        command_info->argv[command_info->argc-1] = token;
    }
    command_info->argv = my_realloc(command_info->argv, sizeof(char*)*command_info->argc, sizeof(char*)*command_info->argc+1);
    command_info->argv[command_info->argc] = NULL;
}

void ignoreSignal(int sig)
{
    signal(sig, SIG_IGN);
}

void print_prompt(void)
{
    char *current_directory = NULL;

    current_directory = getcwd(NULL, 0);
    my_putstr(current_directory);
    write(1, "$ ", 2);
    free(current_directory);
}

int test_end_char(char *line, int len_line)
{
    for (int i = 0; i < len_line; i++) {
        if (line[i] == '\n' && i == 0)
            return 1;
        if (line[i] == 0)
            return 1;
    }
    return 0;
}

int main(void)
{
    int last_status_code = 0;
    char **env = load_environ();
    char *line = NULL;
    size_t size = 0;
    int read = 0;

    ignoreSignal(SIGINT);
    while (1) {
        if (isatty(stdin->_fileno))
            print_prompt();
        size = 0;
        line = NULL;
        read = getline(&line, &size, stdin);
        if(line[0] == '\n')
            continue;
        if(line[0] == '\0' || line[0] == 0)
            break;
        for(int i = 0; line[i] !='\0'; i++) {
            if(line[i] == '\n'){
                line[i] = '\0';
            }
        }
        if (read > 1) {
            command_info_t command_info;
            parse_inputs(line, &command_info);
            exec_command(&command_info, &env);
            last_status_code = command_info.status;
        }
        free(line);
        if (!isatty(stdin->_fileno))
            return last_status_code;
    }
    return last_status_code;
}