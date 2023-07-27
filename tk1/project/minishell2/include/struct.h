/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#ifndef _STRUCT_H
    #define _STRUCT_H

struct command_info
{
    int argc;
    char **argv;
    int status;
    char *line;
    char *oldpdw;
    int already_fork;
};
typedef struct command_info command_info_t;

struct semicolon_segment
{
    char *command_line;
};
typedef struct semicolon_segment semicolon_segment_t;

struct pipe_segment
{
    char *command_line;
    int fd_pipe[2];
};
typedef struct pipe_segment pipe_segment_t;

#endif
