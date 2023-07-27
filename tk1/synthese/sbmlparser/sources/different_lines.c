/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdlib.h>
#include <stdio.h>

static line_parse_t *lines_value(void)
{
    line_parse_t *make_lines = malloc(sizeof(line_parse_t));

    make_lines->n = 0;
    make_lines->occ = 0;
    make_lines->i = 0;
    make_lines->real = 0;
    make_lines->t = 0;
    return make_lines;
}

static void check_space(line_parse_t *parse, char **buffer, int *lines)
{
    while (buffer[lines[parse->i]][parse->n] ==
    buffer[lines[parse->i + 1]][parse->t]) {
        if (buffer[lines[parse->i]][parse->n] == ' '
        || buffer[lines[parse->i + 1]][parse->t] == ' ')
            return;
        parse->n++;
        parse->t++;
        parse->occ++;
    }
}

static void reset_value(line_parse_t *parse)
{
    parse->i++;
    parse->n = 0;
    parse->occ = 0;
    parse->real = 0;
    parse->t = 0;
}

int *different_lines(char **buffer, int *lines)
{
    line_parse_t *parse = lines_value();

    while (lines[parse->i] != 0) {
        while (buffer[lines[parse->i]][parse->n] == ' ') {
            parse->n++;
            parse->real++;
        }
        while (buffer[lines[parse->i + 1]][parse->t] == ' ')
            parse->t++;
        while (buffer[lines[parse->i]][parse->real] != ' ')
            parse->real++;
        parse->real -= parse->n;
        check_space(parse, buffer, lines);
        if (parse->real == parse->occ)
            lines[parse->i] = 0;
        reset_value(parse);
    }
    return lines;
}
