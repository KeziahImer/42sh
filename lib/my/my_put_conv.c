/*
** EPITECH PROJECT, 2021
** Myputhexa
** File description:
** nothing
*/

#include <stdlib.h>
#include "my.h"

int size_unsigned(unsigned int a)
{
    int cpt = 0;

    for (; a > 0; cpt++)
        a /= 10;
    return cpt;
}

int my_put_hexa_low(unsigned int a)
{
    long remainder = 0;
    int size = 0;
    char *str = NULL;
    int i = 0;

    size = size_unsigned(a);
    str = malloc(sizeof(char) * (size + 1));
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

int my_put_hexa_upper(unsigned int a)
{
    long remainder = 0;
    int size = 0;
    char *str = NULL;
    int i = 0;

    size = size_unsigned(a);
    str = malloc(sizeof(char) * (size + 1));
    for (; a > 0; i++) {
        remainder = a % 16;
        a /= 16;
        if (remainder >= 10)
            str[i] = remainder + 55;
        else
            str[i] = remainder + 48;
    }
    str[i] = '\0';
    my_revstr(str);
    my_putstr(str);
    free(str);
    return 0;
}

int my_put_oct(unsigned int a)
{
    unsigned int remainder = 0;
    int size = 0;
    char *str = NULL;
    int i = 0;

    size = size_unsigned(a);
    str = malloc(sizeof(char) * (size + 1));
    for (; a > 0; i++) {
        remainder = a % 8;
        a /= 8;
        str[i] = remainder + 48;
    }
    str[i] = '\0';
    my_revstr(str);
    my_putstr(str);
    free(str);
    return 0;
}

int my_put_bin(unsigned int a)
{
    long remainder = 0;
    int size = 0;
    char *str = NULL;
    int i = 0;

    size = size_unsigned(a);
    str = malloc(sizeof(char) * (size + 1));
    for (; a > 0; i++) {
        remainder = a % 2;
        a /= 2;
        str[i] = remainder + 48;
    }
    str[i] = '\0';
    my_revstr(str);
    my_putstr(str);
    free(str);
    return 0;
}
