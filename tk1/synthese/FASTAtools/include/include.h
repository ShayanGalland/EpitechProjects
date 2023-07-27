/*
** EPITECH PROJECT, 2021
** include
** File description:
** function h
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

typedef struct sequence_s {
    char* name;
    char* dna;
} sequence_t;

typedef struct fasta_s {
    int mode;
    int k;
    int n_seqs;
    sequence_t* sequences;
} fasta_t;
int my_strlen(char const *str);
int my_strcmp(const char *str1, const char *str2);
char *my_revstr(char *str);
void my_itoa(char *buffer, int number, int base);
int open_read(char *file_path, char **data_buffer, int *data_buffer_length);
void fasta_tool(fasta_t *fasta, char *file);
char **my_split(char **tab, char *str, char s);
char **open_file_into_array(char *file_path, int *len);
void error_and_help(int argc, char **argv);
void check_number(char *str);
int k_mers(char **argv, fasta_t *fasta);
int help(void);

#endif
