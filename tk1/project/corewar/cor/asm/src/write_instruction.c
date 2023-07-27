/*
** EPITECH PROJECT, 2022
** write instruction
** File description:
** write instruction
*/

#include "op.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"
#include "asm.h"
#include <stdlib.h>

int do_coding_bytes(char *str, int fd)
{
    int bytes = 0;
    int nbr = nbr_arg(str);

    str += (get_instruct_size(str) + 1);
    for (int i = 0; i < nbr + 1; i++) {
        if (str[0] == 'r') {
            bytes |= 1;
            bytes = bytes << 2;
        }
        if (str[0] == '%') {
            bytes |= 2;
            bytes = bytes << 2;
        }
        if (str[0] != 'r' && str[0] != '%') {
            bytes |= 3;
            bytes = bytes << 2;
        }
        if (i != nbr)
            str = skip_str(str, ',');
    }
    write(fd, &bytes, 1);
    return 0;
}

int write_direct(char *str, int fd, char **ori, int line)
{
    int tmp = 0;

    str++;
    if (str[0] == ':') {
        str++;
        tmp = get_label_adress(ori, str, line);
        tmp = convert(tmp);
        write(fd, &tmp, 4);
    } else {
        tmp = my_getnbr(str);
        tmp = convert(tmp);
        write(fd, &tmp, 4);
    }
    return 0;
}

int write_direct_index(char *str, int fd, char **ori, int line)
{
    int tmp = 0;

    str++;
    if (str[0] == ':') {
        str++;
        tmp = get_label_adress(ori, str, line);
        tmp = ((tmp >> 8) | (tmp << 8));
        write(fd, &tmp, 2);
    } else {
        tmp = my_getnbr(str);
        tmp = ((tmp >> 8) | (tmp << 8));
        write(fd, &tmp, 2);
    }
    return 0;
}

int write_args_index(char *str, int fd, char **ori, int line)
{
    char **args = NULL;
    int nbr = 0;

    str += (get_instruct_size(str) + 1);
    args = my_str_to_word_array(args, str, ',');
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == 'r') {
            args[i]++;
            nbr = my_getnbr(args[i]);
            write(fd, &nbr, 1);
        }
        if (args[i][0] == '%') {
            write_direct_index(args[i], fd, ori, line);
        }
    }
    return 0;
}

int write_args(char *str, int fd, char **ori, int line)
{
    char **args = NULL;
    int nbr = 0;

    str += (get_instruct_size(str) + 1);
    args = my_str_to_word_array(args, str, ',');
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == 'r') {
            args[i]++;
            nbr = my_getnbr(args[i]);
            write(fd, &nbr, 1);
        }
        if (args[i][0] == '%') {
            write_direct(args[i], fd, ori, line);
        }
    }
    return 0;
}

int is_index(char *instruct)
{
    char *lib[] = {"zjmp", "ldi", "sti", "fork", "ldi", "lfork", NULL};

    for (int i = 0; lib[i] != NULL; i++)
        if (my_strcmp(instruct, lib[i]) == 0)
            return 1;
    return 0;
}

char *skip_label(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != ' '; i++) {
        count++;
        if (str[i] == ':')
            str += (count + 1);
    }
    return str;
}

int need_coding_bytes(char *str)
{
    char *lib[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; lib[i] != NULL; i++)
        if (my_strncmp(str, lib[i], my_strlen(lib[i])) == 0)
            return 1;
    return 0;
}

int write_instruction(asm_t *inst, int fd)
{
    inst->instruct++;
    for (int j = 0; inst->instruct[j] != NULL; j++) {
        for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
            inst->instruct[j] = skip_label(inst->instruct[j]);
            if (my_strncmp(inst->instruct[j], op_tab[i].mnemonique,
            get_instruct_size(inst->instruct[j])) == 0) {
                write(fd, &op_tab[i].code, 1);
                if (need_coding_bytes(inst->instruct[j]) == 0)
                    do_coding_bytes(inst->instruct[j], fd);
                if (is_index(op_tab[i].mnemonique) == 1)
                    write_args_index(inst->instruct[j], fd, inst->ori_instruct, j);
                else
                    write_args(inst->instruct[j], fd, inst->ori_instruct, j);
            }
        }
    }
    return 0;
}