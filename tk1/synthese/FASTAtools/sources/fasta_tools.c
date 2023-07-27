/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strupcase(char *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        if (str[n] >= 'a' && str[n] <= 'z')
            str[n] = str[n] - 32;
    return (str);
}
char *clean_dna(char *dna)
{
    int count = 0;
    int n = 0;
    char *new_dna = NULL;

    dna = my_strupcase(dna);
    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'A' || dna[i] == 'T' || dna[i] == 'G' || dna[i] == 'C' 
        || dna[i] == 'N')
            count++;
    }
    new_dna = malloc(sizeof(char) * (count + 1));
    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'A' || dna[i] == 'T' ||
        dna[i] == 'G' || dna[i] == 'C' || dna[i] == 'N') {
            new_dna[n] = dna[i];
            n++;
        }
    }
    new_dna[count+1] = '\0';
    return new_dna;
}
char *my_strcat_aloc(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int new_len = len1 + len2 + 1;
    char *str = malloc(sizeof(char) * new_len);
    int offset_str = 0;

    for (int i = 0; i < new_len - 1; i++) {
        if (i < len1) {
            str[i] = str1[i];
            offset_str++;
        } else
            str[i] = str2[i - offset_str];
    }
    str[new_len - 1] = '\0';
    return str;
}
void create_sequences(fasta_t *fasta, char **array, int len) 
{
    int count = 0;

    for(int i = 0; i < len; i++) {
        if(array[i][0] == '>')
            count++;
    }
    fasta->n_seqs = count;
    fasta->sequences = malloc(sizeof(sequence_t) * count);
    for(int i = 0; i < fasta->n_seqs; i++) {
        fasta->sequences[i].name = NULL;
        fasta->sequences[i].dna = NULL;
    }
}
void read_sequences(fasta_t *fasta, char **array, int len)
{
    int seq_it = -1;

    for(int i = 0; i < len; i++) {
        if(array[i][0] == '>')
        {
            seq_it++;
            fasta->sequences[seq_it].name = strdup(array[i]);
        } 
        else if(seq_it > -1)
        {
            if(fasta->sequences[seq_it].dna == NULL)
                fasta->sequences[seq_it].dna = array[i];
            else
                fasta->sequences[seq_it].dna = my_strcat_aloc(fasta->sequences[seq_it].dna, array[i]);
        }
    }
}
void clean_sequences(fasta_t *fasta, char **array, int len)
{
    for(int i = 0; i < fasta->n_seqs; i++) {
        fasta->sequences[i].dna = clean_dna(fasta->sequences[i].dna);
    }
}


void fasta_mode_1(fasta_t *fasta)
{
    for(int i = 0; i < fasta->n_seqs; i++){
        printf("%s\n", fasta->sequences[i].name);
        printf("%s\n", fasta->sequences[i].dna);
    }
}

void print_rna(char c) {

    if(c == 'T')
        printf("%c", 'U');
    else
        printf("%c", c);
}
void fasta_mode_2(fasta_t *fasta)
{
    for(int i = 0; i < fasta->n_seqs; i++){
        printf("%s\n", fasta->sequences[i].name);
        for(int n = 0; fasta->sequences[i].dna[n] != '\0'; n++) {
            print_rna(fasta->sequences[i].dna[n]);
        }
        printf("\n");
    }
}

void print_reverse_complement(char c) 
{
    if(c == 'A')
        printf("%c", 'T');
    if(c == 'T')
        printf("%c", 'A');
    if(c == 'C')
        printf("%c", 'G');
    if(c == 'G')
        printf("%c", 'C');
    if(c == 'N')
        printf("%c", 'N');
}
void fasta_mode_3(fasta_t *fasta)
{
    for(int i = 0; i < fasta->n_seqs; i++) {
        printf("%s\n", fasta->sequences[i].name);
        for(int n = strlen(fasta->sequences[i].dna); n >= 0; n--) {
            print_reverse_complement(fasta->sequences[i].dna[n]);
        }
        printf("\n");
    }
}

typedef struct k_mers_s {
    char** k_mers;
    int count;
} k_mers_t;




void sort_array(char** array, int len)
{
    char* buffer = malloc(sizeof(char) * strlen(array[0]));

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len-i-1; j++) {
            if(my_strcmp(array[j], array[j+1]) > 0) {
                strcpy(buffer, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], buffer);
            }
        }
    }
}
int exists_in(k_mers_t* k_mers, char* k_mer)
{
    for(int i = 0; i < k_mers->count; i++) {
        if(strcmp(k_mer, k_mers->k_mers[i]) == 0)
            return 1;
    }
    return 0;
}
void add_in(k_mers_t* k_mers, char* k_mer) 
{
    k_mers->k_mers = realloc(k_mers->k_mers, sizeof(char*)*(k_mers->count+1));
    k_mers->count++;
    k_mers->k_mers[k_mers->count-1] = strdup(k_mer);
}
void fasta_mode_4(fasta_t* fasta)
{
    char* k_mers_buffer = malloc(sizeof(char) * (fasta->k + 1));
    k_mers_t k_mers;

    k_mers.count = 0;
    k_mers.k_mers = NULL;
    k_mers_buffer[fasta->k+1] = '\0';
    for(int i = 0; i < fasta->n_seqs; i++) {
        for(int n = 0; n+fasta->k < strlen(fasta->sequences[i].dna); n++) {
            for(int k = 0; k < fasta->k; k++) {
                k_mers_buffer[k] = fasta->sequences[i].dna[n+k];
            }
            if(!exists_in(&k_mers, k_mers_buffer))
                add_in(&k_mers, k_mers_buffer);
        }
    }
    sort_array(k_mers.k_mers, k_mers.count);
    for(int i = 0; i < k_mers.count; i++) {
        printf("%s\n", k_mers.k_mers[i]);
    }
}
void fasta_tool(fasta_t *fasta, char *file_path)
{
    int len = 0;
    char **array = open_file_into_array(file_path, &len);

    create_sequences(fasta, array, len);
    read_sequences(fasta, array, len);
    clean_sequences(fasta, array, len);

    if(fasta->mode == 1)
        fasta_mode_1(fasta);
    if(fasta->mode == 2)
        fasta_mode_2(fasta);
    if(fasta->mode == 3)
        fasta_mode_3(fasta);
    if(fasta->mode == 4)
        fasta_mode_4(fasta);
}