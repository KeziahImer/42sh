/*
** EPITECH PROJECT, 2021
** Printf
** File description:
** Adress
*/

#include "my.h"
#include <stdlib.h>

int my_put_adress(long long a)
{
    long long remainder = 0;
    int size = size_unsigned(a);
    char *str = NULL;
    int i = 0;

    my_putstr("0x");
    str = malloc(sizeof(char) * size + 1);
    for (; a > 0; i++) {
        remainder = a % 16;
        a /= 16;
        if (remainder >= 10)
            str[i] = remainder + 87;
        else
            str[i] = remainder + 48;
    }
    str[i] = '\0';
    my_revstr(str);
    my_putstr(str);
    free(str);
    return 0;
}
