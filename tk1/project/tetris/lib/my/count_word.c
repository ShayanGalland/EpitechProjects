/*
** EPITECH PROJECT, 2022
** count_word
** File description:
** hidenp+1
*/

int count_word(char *word, char *str)
{
    int x = 0;

    for (int n = 0, i = 0; str[n] != '\0'; n++) {
        if (str[n] == word[0] && (n == 0 || str[n - 1] == ' ')) {
            n++;
            i = 1;
        }
        if (str[n] == word[i] && i >= 1)
            i++;
        else
            i = 0;
        if (word[i] == '\0' && (str[n + 1] == ' ' || str[n + 1] == '\0')) {
            i = 0;
            x++;
        }
    }
    return x;
}