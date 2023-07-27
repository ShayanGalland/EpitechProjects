/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

int err_cd(command_info_t *cmd)
{
    if (cmd->argv[1][0] == '~')
        return 1;

    if (access(cmd->argv[1], F_OK) == -1) {
        putstr_er(cmd->argv[1]);
        write(2, ": No such file or directory.\n", 29);
        return 0;
    }

    if (access(cmd->argv[1], R_OK) == -1) {
        putstr_er(cmd->argv[1]);
        write(2, ": Permission denied.\n", 21);
        return 0;
    }
    
    struct stat sb;
    if( !(stat(cmd->argv[1], &sb) == 0 && S_ISDIR(sb.st_mode))){
        putstr_er(cmd->argv[1]);
        write(2, ": No such file or directory.\n", 29);
        return 0;
    }


    return 1;
}

void cd_two_args(char **env, command_info_t *cmd)
{
    if (cmd->argv[1][0] == '-') {
        char* old = search_in_env(env, "OLDPWD=");
        if(old == NULL) {
            write(2, ": No such file or directory.\n", 29);
            return;
        }
        chdir(old);
        return;
    }
    if (cmd->argv[1][0] == '~') {
        chdir(search_in_env(env, "HOME="));
        return;
    }
    if (!err_cd(cmd))
        return;
    if (cmd->argv[1][0] != '~' && cmd->argv[1][0] != '-')
        chdir(cmd->argv[1]);
}

void buildtin_cd(command_info_t *cmd, char **env)
{
    char *pwd = NULL;

    if (cmd->argc == 2)
        cd_two_args(env, cmd);
    else {
        if (cmd->argc == 1){
            char* home = search_in_env(env, "HOME=");
            if(home)
                chdir(home);
            else
                write(2, "cd: No home directory.\n", 23);
        }
        else
            write(2, "cd: Too many arguments.\n", 24);
    }
    pwd = getcwd(NULL, 0);
    env = mod_env(env, "OLDPWD=", my_strcat_aloc("OLDPWD=",search_in_env(env, "PWD=")));
    env = mod_env(env, "PWD=", my_strcat_aloc("PWD=",getcwd(NULL, 0)));
    free(pwd);
}

void buildtin_exit(command_info_t *command_info)
{
    int return_code = 0;

    if (command_info->argc == 1 || command_info->argc == 2) {
        return_code = 0;
        if (command_info->argc == 2)
            return_code = my_getnbr(command_info->argv[1]);
        write(1, "exit\n", 5);
        exit(return_code);
    }
}
