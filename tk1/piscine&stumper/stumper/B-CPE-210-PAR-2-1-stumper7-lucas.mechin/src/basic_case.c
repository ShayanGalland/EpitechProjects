/*
** EPITECH PROJECT, 2022
** basic case
** File description:
** simple case
*/

void basic(char_t *mem_char, char *str, int place)
{
    int valide = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str[place])
            valide++;
        if (valide == 1 && i == place)
            printf("%c:%d\n", str[place], mem_char->count[place]);
    }
}

void char_count(char_t *mem_char, char *str, int place)
{
    if (mem_char->status == 0)
        basic(mem_char, str, place);
}

int analyse_char(int j, int i, char *str)
{
    int count = 0;

    if (str[i] == str[j])
        count++;
    return count;
}
