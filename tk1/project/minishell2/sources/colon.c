/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

int delim_colon(char *line, char ***env)
{
    int sect = count_semi_secs(line);
    semicolon_segment_t *sections = malloc(sizeof(semicolon_segment_t)*sect);
    int prev_ix = 0;
    int cur_ix = -1;
    int size = 0;
    int last_ret = 0;

    for (int i = 0; i < sect; i++) {
        sections[i].command_line = NULL;
        cur_ix++;
        prev_ix = cur_ix;
        while (is_delimiter(line, cur_ix) != 1 && line[cur_ix] != '\0')
            cur_ix++;
        size = my_strlen(line)+1;
        sections[i].command_line = malloc(sizeof(char)*size);
        my_memset(sections[i].command_line, '\0', size);
        my_memcpy(&line[prev_ix],sections[i].command_line, cur_ix-prev_ix);
        sections[i].command_line = delete_space(sections[i].command_line);
        last_ret = exec_semicolonsection(&sections[i], env);
    }
    free(sections);
    return last_ret;
}

void set_semicol(int count, pipe_segment_t *sect, semicolon_segment_t *semi_sec)
{
    int prev_ix = 0;
    int current_ix = -1;
    for(int i = 0; i < count; i++) {
        sect[i].command_line = NULL;
        current_ix++;
        prev_ix = current_ix;
        while(is_delimiter(semi_sec->command_line, current_ix) != 2 && semi_sec->command_line[current_ix] != '\0')
            current_ix++;
        int size = my_strlen(semi_sec->command_line)+1;
        sect[i].command_line = malloc(sizeof(char)*size);
        my_memset(sect[i].command_line, '\0', size);
        my_memcpy(&semi_sec->command_line[prev_ix],sect[i].command_line, current_ix-prev_ix);
        sect[i].command_line = delete_space(sect[i].command_line);
    }
}

void exec_pipe_section_2(pipe_segment_t *section_1, pipe_segment_t *section_2, char ***env)
{
    pid_t pid;
    int fd[2];
    int status = 0;

    pipe(fd);
    pid = fork();
    if(pid == 0) {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        command_info_t command_info;
        command_info.already_fork = 0;
        command_info.status = 0;
        command_info.line = section_1->command_line;
        inf_gestion(&command_info, 2, env);
        exit(0);
    }
    else {
        pid = fork();
        if(pid==0) {
            dup2(fd[0], 0);
            close(fd[1]);
            close(fd[0]);
            command_info_t command_info;
            command_info.already_fork = 0;
            command_info.status = 0;
            command_info.line = section_2->command_line;
            inf_gestion(&command_info, 2, env);
            exit(0);
        }
        else {
            close(fd[0]);
            close(fd[1]);
            waitpid(pid, &status, 0);
        }
    }
}

int exec_semicolonsection(semicolon_segment_t *semi_sec, char ***env)
{
    int sect = count_pipe_sections(semi_sec->command_line);
    int ret = 0;

    if(sect == 1) {
        command_info_t command_info;
        command_info.status = 0;
        command_info.already_fork = 0;
        command_info.line = semi_sec->command_line;
        inf_gestion(&command_info, 2, env);
        ret = command_info.status;
    } else {
        pipe_segment_t *sections = malloc(sizeof(pipe_segment_t)*sect);
        set_semicol(sect, sections, semi_sec);

        exec_pipe_section_2(&sections[0], &sections[1], env);
        free(sections);
    }

    return ret;
}

int count_semi_secs(char *line)
{
    int count = 0;
    int del = 0;

    for (int i = 0; line[i] != '\0';i++){
        del = is_delimiter(line, i);
        if (del == 1)
            count++;
    }
    return count+1;
}
