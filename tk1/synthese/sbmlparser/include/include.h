/*
** EPITECH PROJECT, 2021
** include
** File description:
** function h
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

typedef struct  line_parse_s {
    int n;
    int occ;
    int i;
    int real;
    int t;
} line_parse_t;
char **my_str_to_word_array_synthesis(char const *str);
char **my_split(char **tab, char *str, char s);
int my_strlen(char const *str);
int skip_quote(char *str, int i);
int find_quote(char c);
int open_read(char *file_path, char **data_buffer, int *data_buffer_length);
int *find_lines(char **buffer, int *lines);
void separate_str(char *str);
void fil_array_sbml_parser(int *lines, char **buffer, int len);
int *different_lines(char **buffer, int *lines);
char *rm_start_spaces(char *str);
int count_array(char **array);
void fil_array_sbml_parser(int *lines, char **buffer, int len);
int real_len(int *lines, int len);
int find_no_nul(char **array, int shift);
int *find_lines(char **buffer, int *lines);
int alphabetic_array(char **array, int shift);
char **str_in_alpha_array(char *str);
int alphabetic(int *lines, char **buffer, int len);
int find_no_zero(int *lines);
int simple_i_flag(char *comp, char *file);
int e_flags(char *comp, char *file);
int j_flags(char *comp, char *file);
const char *my_strstr(const char *str, const char *token);
char *search_in_env(char **env, char *str);
int find_variable(const char *variable_name, char **env);
char *my_strcat_aloc(char *str1, char *str2);
int my_strcmp(const char *str1, const char *str2);
char *fil_product(char *str, int i);
void prt_in_alphabetic(char **array, char *comp);
int find_tag(char *comp, char **sbml);
int select_tag(char *tag);
int search_tag(char *comp, char **sbml, char *new_comp);
void other(char *comp, char **sbml);
void reaction(char *comp, char **sbml);
char *find_product2(char *str);
void species(char *comp, char **sbml);
void compartment(char *comp, char **sbml);
char *find_product(char *str);
int no_comp(char *file);

#endif
