#include <string.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *reverse_string(char *str)
{
    char time = 0;
    int i = 0;
    int j = my_strlen(str);

    while (i < j - 1) {
        time = str[i];
        str[i] = str[j - 1];
        str[j - 1] = time;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
