/*
** EPITECH PROJECT, 2021
** Printf
** File description:
** Print invisible char
*/

#include "my.h"

int size_oct(int a)
{
    int cpt = 0;

    for (; a > 0; cpt++)
        a /= 8;
    return cpt;
}

void display_zero(int cpt)
{
    for (; cpt < 3; cpt++)
        my_putchar('0');
}

int my_put_invis(char *str)
{
    int cpt = 0;
    int copy = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            cpt = size_oct(str[i]);
            display_zero(cpt);
            copy = str[i];
            my_put_oct(copy);
        } else
            my_putchar(str[i]);
    }
    return 0;
}
