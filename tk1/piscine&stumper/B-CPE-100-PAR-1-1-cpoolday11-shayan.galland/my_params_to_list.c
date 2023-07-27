/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** y
*/

#ifndef TEST_H_
#define TEST_H_

struct s_person
{
    char *first_name;
    char *last_name;
    int phone_nb
};

int view_struct(struct s_person *person);
struct s_person *new_person(char *first_name, char *last_name, int phone_nb);
char *my_strdup(char *str);

#endif /* TEST_H_ */

int view_struct (struct s_person *person)
{
    my_putstr((*person).first_name);
    my_putstr(person->last_name);
    my_putnbr(person->phone_nb);

    return(0);
}

struct s_person *new_person(char *first_name, char *last_name, int phone_nb)
{
    struct s_person *person;

    person = malloc(sizeof(struct s_person));
    if (person == NULL)
        return(NULL);
    person->first_name = my_srdup(first_name);
    person->last_name = my_strdup(last_name);
    person->phone_nb = phone_nb;
    return (person);
}

int main(int ac, char *av[])
{
    struct s_person *person;

    person = new_person("Sherlock", "Holmes", 3034242);
    view_struct(person);
    free(person);
    return(0);
}

