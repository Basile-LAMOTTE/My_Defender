/*
** EPITECH PROJECT, 2021
** lib
** File description:
** intochar
*/

#include "../../include/my.h"

char *intostring(int nb)
{
    int i = 0;
    int x = 0;
    int res = nb;
    while (res > 0) {
        res = res / 10;
        i++;
    }
    char *str = malloc(sizeof(int) * i + 1);
    while (x < i) {
        str[x++] = (nb % 10) + '0';
        nb = nb / 10;
    }
    str[x] = '\0';
    my_revstr(str);
    return (str);
}