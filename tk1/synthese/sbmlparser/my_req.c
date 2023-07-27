#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int len = 0;

    for (int n = 0; str[n] != '\0'; n++)
        len++;
    return (len);
}

char *rm_start_spaces(char *str)
{
    int count = 0;
    int i = 0;
    int len = 0;
    char *new_str = NULL;

    if (str[0] != ' ')
        return str;
    while (str[i] == ' ')
        i++;
    len = my_strlen(str) - i;
    new_str = malloc(sizeof(char) * (len + 1));
    for (int n = 0; n < len; n++) {
        new_str[n] = str[i];
        i++;
    }
    return new_str;
}

int main(int argc, char **argv)
{
    printf("%s", rm_start_spaces(argv[1]));
}