/*
** EPITECH PROJECT, 2022
** get data
** File description:
** get data
*/

char *skip_str(char *str, char param)
{
    while (str[0] != param)
        str++;
    str++;
    return str;
}

int get_instruct_size(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != ' '; i++)
        count++;
    return count;
}

int nbr_arg(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            count++;
    return count;
}
