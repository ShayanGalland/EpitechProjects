/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** emacs
*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char **split_string(char const *str)
{
    int count = 0;
    int count_len = 0;
    int m = 0;
    int len_str = my_strlen(str);
    char **res = NULL;

    for (int i = 0;i != len_str-1;i++) {
        while (str[i] < 64 && str[i] > 91 || str[i] < 96 && str[i] > 123) {
            i++;
            if (str[i+1] > 64 && str[i+1] < 91 || str[i+1] > 96 && str[i+1] < 123)
                count++;
        }
    }
    res = malloc(sizeof(char)*(count+2));
    for (int n = 0;n != len_str+1;n++) {
        while (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123) {
            count_len++;
            if (str[i+1] < 64 && str[i+1] > 91 || str[i+1] < 96 && str[i+1] > 123) {
                res[n] = malloc(sizeof(char)*(count_len+1));
                count_len=0;
            }
        }
        m = n;
    }
    for (int z = 0;z != m;z++) {
        for (int 
        
    }
    

    return res;
}


/*
char **split_string(char const *str)
{
    int count = 0;
    int a = 0;
    int b = 0;
    int n = 0;
    int y = 0;
    char **res = NULL;



    
    for (int p = 0;str[p] != '\0';p++) {
        while (str[y] < 64 && str[y] > 91 || str[y] < 96 && str[y] > 123) {
            y++;
        }
        b = p;
        y++;
    }


    for (int p = 0;str[p] != '\0';p++) {
	while (str[i] < 64 && str[i] > 91 || str[i] < 96 && str[i] > 123) {
            a++;
            i++;
	}
        res[p] = malloc(sizeof(char)*(a+1));
        i++;
    }






    
    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123) {
            count++;
            res[n][count] = str[i];
        }
        else
            n++;
    }
    
    
    
    return res;
}
