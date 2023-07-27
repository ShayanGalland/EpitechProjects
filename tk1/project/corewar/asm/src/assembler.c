/*
** EPITECH PROJECT, 2022
** assembler
** File description:
** assembler
*/

#include "asm.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int write_all(asm_t *inst, int fd, header_t *header)
{
    int empty = 0;
    int size = convert(header->prog_size);

    write(fd, &header->magic, 4);
    write(fd, &header->prog_name, PROG_NAME_LENGTH);
    write(fd, &empty, 4);
    write(fd, &size, 4);
    write(fd, &header->comment, COMMENT_LENGTH);
    write(fd, &empty, 4);
    inst->instruct += 2;
    write_instruction(inst, fd);
    return 0;
}

int do_asm(char *filename)
{
    int fd = 0;
    header_t *header = malloc(sizeof(header_t));
    asm_t *inst = malloc(sizeof(asm_t));
    char **buf = NULL;

    if (handle_error(filename) == -1)
        return -1;
    fd = create_cor_file(filename);
    if (fd == -1)
        return -1;
    inst->instruct = reading_file(filename);
    inst->ori_instruct = reading_file(filename);
    while (inst->instruct[0][0] == '#') {
        inst->instruct++;
        inst->ori_instruct++;
    }
    while (inst->ori_instruct[0][0] == '.')
        inst->ori_instruct++;
    init_header(inst->instruct, header);
    write_all(inst, fd, header);
    return 0;
}