#include <string.h>
#include <stdio.h>
#include <unistd.h>

void py_putchar(char c)
{
    write(1, &c, 1);
}

int show_string(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        py_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
