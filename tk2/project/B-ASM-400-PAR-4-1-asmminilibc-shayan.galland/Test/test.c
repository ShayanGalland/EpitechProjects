#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int my_strlen(char *str);
char *my_strchr(char *str, int n);
char *my_strrchr(char *str, int n);
void *my_memset(void *str, int n, size_t count);
void* my_memcpy(void* dest, void* src, size_t count);
int my_strcmp(char *str1, char *str2);
void* my_memmove(void* dest, void* src, size_t count);
int my_strncmp(char *first, char *second, size_t length);
int my_strcasecmp(char *s1,char *s2);
char *my_strstr(char* foin, char* aiguille);
char * my_strpbrk(char *str, char *char_list);
size_t my_strcspn( const char * str, const char *char_list);


void memmove_test(int ac, char *str, int n)
{
    ac = ac;
    char *ret = my_memmove(str, str + 4, strlen(str) - 4 + 1);
    printf("%s", ret);
}

void strcmp_test(int ac, char *str1, char *str2)
{
    if (ac < 3) {
        printf("ERROR\n");
        exit(0);
    }
    int ret = my_strcmp(str1, str2);
    printf("%d", ret);
}

void memcpy_test(int ac, char *dest, char *src, size_t count)
{
    if (ac < 4) {
        printf("ERROR\n");
        exit(0);
    }

    char *ret = my_memcpy(dest, src, count);
    printf("%s", ret);
}

void memset_test(int ac, char *str, char c, size_t count)
{
    if (ac < 4) {
        printf("ERROR\n");
        exit(0);
    }
    char *ret = my_memset(str, c, count);
    printf("%s", ret);
}

void strrchr_test(int ac, char *str, char c)
{
    if (ac < 3) {
        printf("ERROR\n");
        exit(0);
    }

    char *ret = my_strrchr(str, c);
    printf("%s", ret);
}

void strchr_test(int ac, char *str, char c)
{
    if (ac < 3) {
        printf("ERROR\n");
        exit(0);
    }

    char *ret = my_strchr(str, c);
    printf("%s", ret);
}

void strlen_test(int ac, char *str)
{
    if (ac < 2) {
        printf("ERROR\n");
        exit(0);
    }
    int len = my_strlen(str);
    printf("The length of the string is: %d\n", len);
    exit(0);
}

void main(int ac, char **av)
{
    char arr[] = "memcpy vs memmove";

    strlen_test(ac, av[1]);
    //strchr_test(ac, av[1], av[2][0]);
    //strrchr_test(ac, av[1], av[2][0]);
    //memset_test(ac, av[1], av[2][0], atoi(av[3]));
    //memcpy_test(ac, av[1], av[2], atoi(av[3]));
    //strcmp_test(ac, av[1], av[2]);
    //memmove_test(ac, arr, atoi(av[1]));
    //printf("\n%s", my_memmove(av[1], av[2], atoi(av[3])));?
    //printf("%d", my_strncmp(av[1], av[2], atoi(av[3])));
    //printf("\n%d", my_strcasecmp(av[1], av[2]));
    //printf("\n%s", my_strstr(av[1], av[2]));
    //printf("\n%s", my_strpbrk(av[1], av[2]));
    //printf("\n%d",my_strcspn(av[1], av[2]));

    //printf("\n%d", strlen(av[1]));
    //printf("\n%s", strchr(av[1], av[2][0]));
    //printf("\n%s", strrchr(av[1], av[2][0]));
    //printf("\n%s", memset(av[1], av[2][0], atoi(av[3])));
    //printf("\n%s", memcpy(av[1], av[2], atoi(av[3])));
    //printf("\n%s", memcpy(arr, arr + 4, strlen(arr) - 4 + 1));
    //printf("\n%d", strcmp(av[1], av[2]));
    //printf("\n%s", memmove(av[1], av[2], atoi(av[3])));?
    //printf("\n%d", strncmp(av[1], av[2], atoi(av[3])));
    //printf("\n%d", strcasecmp(av[1], av[2]));
    //printf("\n%s", strstr(av[1], av[2]));
    //printf("\n%s", strpbrk(av[1], av[2]));
    printf("\n%d",strcspn(av[1], av[2]));
}

