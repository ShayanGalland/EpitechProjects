/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** project main
*/

#include "../include/include.h"
#include <stdio.h>
#include <stdlib.h>

int help(void)
{
    printf("USAGE\n");
    printf("\t./FASTAtools option [k]\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("\toption 1: read FASTA from the standard input, ");
    printf("write the DNA sequences to the standard output\n");
    printf("\toption 2: read FASTA from the standard input, ");
    printf("write the RNA sequences to the standard output\n");
    printf("\toption 3: read FASTA from the standard input, ");
    printf("write the reverse complement to the standard output\n");
    printf("\toption 4: read FASTA from the standard input, ");
    printf("write the k-mer list to the standard output\n");
    printf("\toption 5: read FASTA from the standard input, ");
    printf("write the coding sequences list to the standard output\n");
    printf("\toption 6: read FASTA from the standard input, ");
    printf("write the amino acids list to the standard output\n");
    printf("\toption 7: read FASTA from the standard input containing ");
    printf("exactly 2 squences, align them and write the result to the ");
    printf("standard output\n\tk: size of the k-mers for option 4\n");
    return 0;
}

int main(int argc, char **argv)
{
    fasta_t fasta;

    error_and_help(argc, argv);
    if (argc == 4)
        fasta.k = k_mers(argv, &fasta);
    if (argv[1][0] >= '1' && argv[1][0] <= '7') {
        fasta.mode = atoi(argv[1]);
        if (argc == 3)
            fasta_tool(&fasta, argv[2]);
        else
            fasta_tool(&fasta, argv[3]);
    }
    else
        return 84;
    return 0;
}
