#include "op.h"
#include "functions.h"
#include "../../include/my.h"

struct program_header
{
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
};
typedef struct program_header program_header_t;

struct program_data
{
    int reg[REG_NUMBER];
    int pc;
    int carry;
};
typedef struct program_data program_data_t;

struct instruction_params_s
{
    int params_count;
    int params_type[MAX_ARGS_NUMBER];
    int params_value[MAX_ARGS_NUMBER];
};
typedef struct instruction_params_s instruction_params_t;

struct instruction_s
{
    int instruction_type;
    instruction_params_t instruction_params;
};
typedef struct instruction_s instruction_t;

struct program
{
    char *program_path;
    int prog_number;
    int load_address;

    program_header_t program_header;
    program_data_t program_data;

    int instruction_in_progress;
    instruction_t current_instruction;
};
typedef struct program program_t;

struct corewar_s
{
    int nbr_cycle_dump;

    int program_count;
    program_t *programs;

    unsigned char *memory;
};
typedef struct corewar_s corewar_t;

struct command_line
{
    int nbr_cycle_dump;
    int program_count;

    char **program_path;
    int *prog_number;
    int *load_address;
};
typedef struct command_line command_line_t;

int read_command_line(int argc, char **argv, command_line_t *command_line)
{
    command_line->nbr_cycle_dump = 0;
    command_line->program_count = 0;
    command_line->program_path = NULL;
    command_line->prog_number = NULL;
    command_line->load_address = NULL;

    int current_program = 0;
    command_line->program_path = realloc(command_line->program_path, sizeof(char *) * (current_program + 1));
    command_line->prog_number = realloc(command_line->prog_number, sizeof(int) * (current_program + 1));
    command_line->load_address = realloc(command_line->load_address, sizeof(int) * (current_program + 1));

    command_line->prog_number[current_program] = -1;
    command_line->load_address[current_program] = -1;

    for (int i = 1; i < argc; i++)
    {

        // option or prog_name
        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i], "-dump") == 0)
            {
                command_line->nbr_cycle_dump = my_getnbr(argv[i + 1]);
            }
            else if (strcmp(argv[i], "-n") == 0)
            {
                command_line->prog_number[current_program] = my_getnbr(argv[i + 1]);
            }
            else if (strcmp(argv[i], "-a") == 0)
            {
                command_line->load_address[current_program] = my_getnbr(argv[i + 1]);
            }

            i++;
        }
        else
        {
            command_line->program_path[current_program] = argv[i];
            current_program++;
            command_line->program_count = current_program;

            command_line->program_path = realloc(command_line->program_path, sizeof(char *) * (current_program + 1));
            command_line->prog_number = realloc(command_line->prog_number, sizeof(int) * (current_program + 1));
            command_line->load_address = realloc(command_line->load_address, sizeof(int) * (current_program + 1));

            command_line->prog_number[current_program] = -1;
            command_line->load_address[current_program] = -1;
        }
    }

    return 1;
}
void printf_command_line(command_line_t *command_line)
{
    my_printf("Corewar:\n");
    my_printf("Dump option: %d\n", command_line->nbr_cycle_dump);
    my_printf("Nbr programs: %d\n", command_line->program_count);
    for (int i = 0; i < command_line->program_count; i++)
    {
        my_printf("Prog: %s\n", command_line->program_path[i]);
        my_printf("n: %d\n", command_line->prog_number[i]);
        my_printf("load: %d\n", command_line->load_address[i]);
    }
}
void free_command_line(command_line_t *command_line)
{
    free(command_line->program_path);
    free(command_line->prog_number);
    free(command_line->load_address);
}

int find_next_prog_number(int prog_count, program_t *programs)
{
    int next_prog_number = 1;
    int taken = 0;
    while (1)
    {
        taken = 0;

        for (int i = 0; i < prog_count; i++)
        {
            if (programs[i].prog_number == next_prog_number)
            {
                taken = 1;
                break;
            }
        }
        if (!taken)
            break;
        next_prog_number++;
    }

    return next_prog_number;
}
int init_corewar(command_line_t *command_line, corewar_t *corewar)
{
    // Allocate main memory for Corewar VM
    corewar->memory = malloc(MEM_SIZE);
    if (!corewar->memory)
    {
        my_printf("Cannot alloc memory\n");
        exit(84);
    }
    my_memset(corewar->memory, 0, MEM_SIZE);

    corewar->nbr_cycle_dump = command_line->nbr_cycle_dump;
    corewar->program_count = command_line->program_count;

    corewar->programs = malloc(sizeof(program_t) * corewar->program_count);
    for (int i = 0; i < corewar->program_count; i++)
    {
        corewar->programs[i].program_path = command_line->program_path[i];
        corewar->programs[i].prog_number = command_line->prog_number[i];
        corewar->programs[i].load_address = command_line->load_address[i];
        if (!load_program_header(corewar->programs[i].program_path, &corewar->programs[i].program_header))
            return 0;
    }

    int address_interval = MEM_SIZE / corewar->program_count;
    int next_adress = 0;

    for (int i = 0; i < corewar->program_count; i++)
    {
        if (corewar->programs[i].prog_number == -1)
            corewar->programs[i].prog_number = find_next_prog_number(corewar->program_count, corewar->programs);

        if (corewar->programs[i].load_address == -1)
        {
            corewar->programs[i].load_address = next_adress;
            next_adress = next_adress + address_interval;
        }
        else
            next_adress = corewar->programs[i].load_address + address_interval;
    }

    for (int i = 0; i < corewar->program_count; i++)
    {
        load_program_asm(corewar, &corewar->programs[i]);
        corewar->programs[i].instruction_in_progress = 0;
        corewar->programs[i].program_data.pc = corewar->programs[i].load_address;
        corewar->programs[i].program_data.carry = 0;
        corewar->programs[i].program_data.reg[0] = corewar->programs[i].prog_number;
        for (int j = 1; j < REG_NUMBER; j++)
        {
            corewar->programs[i].program_data.reg[j] = 0;
        }
    }

    return 1;
}
void free_corewar(corewar_t *corewar)
{
    free(corewar->memory);
    free(corewar->programs);
}

int load_program_asm(corewar_t *corewar, program_t *program)
{
    FILE *fd = fopen(program->program_path, "rb");
    size_t size = 0;

    fseek(fd, sizeof(header_t), SEEK_SET);

    size = fread(&corewar->memory[program->load_address], program->program_header.prog_size, 1, fd);
    if (size != 1)
    {
        my_printf("size fread != 1\n");
        fclose(fd);
        return 0;
    }
    else
    {
        return 1;
    }
}
int load_program_header(char *prog_path, program_header_t *prog_header)
{
    FILE *fd = fopen(prog_path, "rb");
    size_t size = 0;

    if (fd)
    {
        size = fread(prog_header, sizeof(header_t), 1, fd);
        if (size != 1)
        {
            my_printf("size fread != 1\n");
            fclose(fd);
            return 0;
        }
        prog_header->magic = int_to_little_endian(prog_header->magic);
        prog_header->prog_size = int_to_little_endian(prog_header->prog_size);
        if (prog_header->magic != COREWAR_EXEC_MAGIC)
        {
            my_printf("prog_header->magic != COREWAR_EXEC_MAGIC 1\n");
            fclose(fd);
            return 0;
        }
        return 1;
    }
    else
    {
        my_printf("cant open\n");
        return 0;
    }
}

void print_xx_bis(long x, unsigned int number, char *hexa, int n)
{
    while (number != 0)
    {
        x = number % 16;
        if (x < 10)
        {
            n++;
            hexa[n] = 48 + x;
        }
        if (x >= 10)
        {
            n++;
            hexa[n] = 55 + x;
        }
        number /= 16;
    }
    for (int i = n; i >= 0; i--)
        my_printf("%c", hexa[i]);
    free(hexa);
}
int my_compute_power_it(int nb, int p)
{
    long n;
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (n > 2147483647 || n < -2147483647)
        return 0;
    return (nb * my_compute_power_it(nb, p - 1));
}
void print_xx(unsigned int number)
{
    long x = 0;
    int l = 1;
    int n = 0;
    if (number < my_compute_power_it(10, l))
        l++;
    char *hexa = malloc(sizeof(char) * (l + 2));
    print_xx_bis(x, number, hexa, n);
}
void dump_memory(corewar_t *corewar)
{
    for (int i = 0; i < MEM_SIZE / 32; i = i + 32)
    {
        for (int j = 0; j < 32; j++)
        {
            print_xx(corewar->memory[i + j]);
        }
    }
}

void read_params_types(unsigned char coding_value, instruction_params_t *instruction_params)
{
    instruction_params->params_count = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
    {
        int parameter_type = (coding_value >> (6 - (i * 2))) & 0x03;

        switch (parameter_type)
        {
        // Register
        case 0x01:
            instruction_params->params_type[i] = T_REG;
            instruction_params->params_count++;
            break;

        // Direct
        case 0x02:
            instruction_params->params_type[i] = T_DIR;
            instruction_params->params_count++;
            break;

        // Indirect
        case 0x03:
            instruction_params->params_type[i] = T_IND;
            instruction_params->params_count++;
            break;

        case 0x00:
            return;
        }
    }
}
int read_params_value(unsigned char *memory, int start, instruction_params_t *instruction_params, int indexes[MAX_ARGS_NUMBER])
{
    int offset = 0;
    for (int i = 0; i < instruction_params->params_count; i++)
    {
        int params_type = instruction_params->params_type[i];
        int is_param_indexes = indexes[i];

        switch (params_type)
        {
        case T_REG:
            instruction_params->params_value[i] = memory[start + offset];
            offset += 1;
            break;

        case T_DIR:
            if (is_param_indexes)
            {
                instruction_params->params_value[i] = short_to_little_endian(*(short *)(&memory[start + offset]));
                offset += 2;
            }
            else
            {
                instruction_params->params_value[i] = int_to_little_endian(*(int *)(&memory[start + offset]));
                offset += 4;
            }
            break;

        case T_IND:
            instruction_params->params_value[i] = short_to_little_endian(*(short *)(&memory[start + offset]));
            offset += 2;
            break;
        }
    }

    return offset;
}

int read_live_instruction(corewar_t *corewar, program_t *program)
{
    int idx = program->program_data.pc + 1;

    program->current_instruction.instruction_type = 0x01;
    program->current_instruction.instruction_params.params_count = 1;
    program->current_instruction.instruction_params.params_type[0] = T_DIR;
    program->current_instruction.instruction_params.params_value[0] = int_to_little_endian(*(int *)(&corewar->memory[idx]));

    return 4;
}
int read_ld_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x02;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);
    return read;
}
int read_st_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x03;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_add_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x04;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_sub_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x05;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_and_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x06;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_or_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x07;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_xor_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x08;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_zjmp_instruction(corewar_t *corewar, program_t *program)
{
    int idx = program->program_data.pc + 1;

    program->current_instruction.instruction_type = 0x09;
    program->current_instruction.instruction_params.params_count = 1;
    program->current_instruction.instruction_params.params_type[0] = T_IND;
    program->current_instruction.instruction_params.params_value[0] = short_to_little_endian(*(short *)(&corewar->memory[idx]));

    return 2;
}
int read_ldi_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {1, 1, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x0a;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_sti_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 1, 1, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x0b;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_fork_instruction(corewar_t *corewar, program_t *program)
{
    int idx = program->program_data.pc + 1;

    program->current_instruction.instruction_type = 0x0c;
    program->current_instruction.instruction_params.params_count = 1;
    program->current_instruction.instruction_params.params_type[0] = T_IND;
    program->current_instruction.instruction_params.params_value[0] = short_to_little_endian(*(short *)(&corewar->memory[idx]));

    return 2;
}
int read_lld_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x0d;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_lldi_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {1, 1, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x0e;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}
int read_lfork_instruction(corewar_t *corewar, program_t *program)
{
    int idx = program->program_data.pc + 1;

    program->current_instruction.instruction_type = 0x0f;
    program->current_instruction.instruction_params.params_count = 1;
    program->current_instruction.instruction_params.params_type[0] = T_IND;
    program->current_instruction.instruction_params.params_value[0] = short_to_little_endian(*(short *)(&corewar->memory[idx]));

    return 2;
}
int read_aff_instruction(corewar_t *corewar, program_t *program)
{
    int indexes[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    int idx = program->program_data.pc + 1;
    int read = 1;

    program->current_instruction.instruction_type = 0x10;

    unsigned char coding_value = corewar->memory[idx];
    read_params_types(coding_value, &program->current_instruction.instruction_params);

    idx++;
    read += read_params_value(corewar->memory, idx, &program->current_instruction.instruction_params, indexes);

    return read;
}

const char *instruction_code_to_string(int type)
{
    switch (type)
    {
    case 0x01:
        return "live";
    case 0x02:
        return "ld";
    case 0x03:
        return "st";
    case 0x04:
        return "add";
    case 0x05:
        return "sub";
    case 0x06:
        return "and";
    case 0x07:
        return "or";
    case 0x08:
        return "xor";
    case 0x09:
        return "zjmp";
    case 0x0a:
        return "ldi";
    case 0x0b:
        return "sti";
    case 0x0c:
        return "fork";
    case 0x0d:
        return "lld";
    case 0x0e:
        return "lldi";
    case 0x0f:
        return "lfork";
    case 0x10:
        return "aff";
    default:
        return "Invalid";
    }
}
int read_instruction(corewar_t *corewar, program_t *program)
{
    int read = 1;
    unsigned char mnemonic = corewar->memory[program->program_data.pc];

    switch (mnemonic)
    {
    // live
    case 0x01:
        read += read_live_instruction(corewar, program);
        break;

    // ld
    case 0x02:
        read += read_ld_instruction(corewar, program);
        break;

    // st
    case 0x03:
        read += read_st_instruction(corewar, program);
        break;

    // add
    case 0x04:
        read += read_add_instruction(corewar, program);
        break;

    // sub
    case 0x05:
        read += read_sub_instruction(corewar, program);
        break;

    // and
    case 0x06:
        read += read_and_instruction(corewar, program);
        break;

    // or
    case 0x07:
        read += read_or_instruction(corewar, program);
        break;

    // xor
    case 0x08:
        read += read_xor_instruction(corewar, program);
        break;

    // zjmp
    case 0x09:
        read += read_zjmp_instruction(corewar, program);
        break;

    // ldi
    case 0x0a:
        read += read_ldi_instruction(corewar, program);
        break;

    // sti
    case 0x0b:
        read += read_sti_instruction(corewar, program);
        break;

    // fork
    case 0x0c:
        read += read_fork_instruction(corewar, program);
        break;

    // lld
    case 0x0d:
        read += read_lld_instruction(corewar, program);
        break;

    // lldi
    case 0x0e:
        read += read_lldi_instruction(corewar, program);
        break;

    // lfork
    case 0x0f:
        read += read_lfork_instruction(corewar, program);
        break;

    // aff
    case 0x10:
        read += read_aff_instruction(corewar, program);
        break;

    default:
        my_printf("Invalid instruction type\n");
        break;
    }

    my_printf("Instruction: %s, %d, %d\n", instruction_code_to_string(program->current_instruction.instruction_type), read, program->current_instruction.instruction_params.params_count);

    return read;
}



int main(int argc, char **argv)
{
    int test_program = 2;
    command_line_t command_line;
    if (read_command_line(argc, argv, &command_line))
    {
        corewar_t corewar;
        if (!init_corewar(&command_line, &corewar))
        {
            my_printf("Init Error\n");
            return 84;
        }

        printf("Prog size: %d\n", corewar.programs[test_program].program_header.prog_size);
        int start = corewar.programs[test_program].program_data.pc;
        while((corewar.programs[test_program].program_data.pc-start) < corewar.programs[test_program].program_header.prog_size)
            corewar.programs[test_program].program_data.pc += read_instruction(&corewar, &corewar.programs[test_program]);
        
        free_command_line(&command_line);
        free_corewar(&corewar);
    }
    else
    {
        return 84;
    }

    /*
    if (fd)
    {
        fread(&prog_header, sizeof(header_t), 1, fd);
        prog_header.prog_size = int_to_little_endian(prog_header.prog_size);

        printf("name: %s\n", prog_header.prog_name);
        printf("comment: %s\n", prog_header.comment);
        printf("prog size: %d\n", prog_header.prog_size);

        u_int8_t *prog = malloc(prog_header.prog_size);
        fread(prog, prog_header.prog_size, 1, fd);

        // mnemonics
        printf("OP 0: %d\n", prog[0]);                                      // 11
        printf("OP 0: %d\n", prog[1]);                                      // 01 10 10 00
        printf("OP 0: %d\n", prog[2]);                                      // r1
        printf("OP 0: %d\n", short_to_little_endian(*(short *)(&prog[3]))); // 7
        printf("OP 0: %d\n", short_to_little_endian(*(short *)(&prog[5]))); // 1

        printf("OP 1: %d\n", prog[7]);                                  // 1
        printf("OP 1: %d\n", int_to_little_endian(*(int *)(&prog[8]))); // 234

        printf("OP 2: %d\n", prog[12]);                                  // 1
        printf("OP 2: %d\n", prog[13]);                                  // 10 01 00 00
        printf("OP 2: %d\n", int_to_little_endian(*(int *)(&prog[14]))); // 0
        printf("OP 2: %d\n", prog[18]);                                  // 3

        printf("OP 3: %d\n", prog[19]);                                      // 9
        printf("OP 3: %d\n", short_to_little_endian(*(short *)(&prog[20]))); // 7

        free(prog);
    }
    */

    // Chargement des programmes

    // Verification des programmes

    // Execution

    return 0;
}