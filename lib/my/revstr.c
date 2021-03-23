/*
** EPITECH PROJECT, 2020
** My revstr
** File description:
** Rev the string
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i]; ++i);
    return i;
}

char *my_revstr(char *str)
{
    int k = my_strlen(str);
    int cop[my_strlen(str)];
    int i = 0;
    while (str[i] != 0) {
        cop[i] = str[i];
        i = i + 1;
    }
    i = 0;
    while (k > 0) {
        str[i] = cop[k-1];
        k = k - 1;
        i = i + 1;
    }
    return (str);
}