/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

int is_delimiter(char *line, int i)
{
    if (line[i] == ';')
        return 1;
    if (line[i] == '|')
        return 2;
    if (line[i] == '<' && line[i+1] == '<')
        return 3;
    if (line[i] == '<')
        return 4;
    if (line[i] == '>' && line[i+1] == '>')
        return 5;
    if (line[i] == '>')
        return 6;
    return 0;
}

int count_sections(char *line)
{
    int count = 0;
    int del = 0;

    for (int i = 0; line[i] != '\0';i++) {
        del = is_delimiter(line, i);
        if (del > 0)
            count++;
        if (del == 3 || del == 5)
            i++;
    }
    return count+1;
}

int count_pipe_sections(char *line)
{
    int count = 0;
    int del = 0;

    for (int i = 0; line[i] != '\0';i++){
        del = is_delimiter(line, i);
        if (del == 2)
            count++;
    }
    return count+1;
}

void exec_pipe_section(pipe_segment_t *pipe, char ***env)
{
    return;
}
