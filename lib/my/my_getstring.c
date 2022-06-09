/*
** EPITECH PROJECT, 2021
** getnbr
** File description:
** nothing
*/

#include "my.h"
#include <stdlib.h>

int verify_sign(int result)
{
    if (result < 0)
        return 1;
    return 0;
}

char *my_getstring(int result)
{
    int sign = 1;
    int i = 0;
    int cpt = 1;
    int dcm = 1;
    char *str = NULL;

    i = verify_sign(result);
    if (i == 1)
        sign = -1;
    result *= sign;
    for (; result / dcm >= 10; cpt++)
        dcm = dcm * 10;
    str = malloc(sizeof(char) * cpt + 1);
    if (sign == -1)
        str[0] = '-';
    for (; dcm > 0; i++, dcm /= 10)
        str[i] = ((result / dcm) % 10 + 48);
    str[i] = '\0';
    return str;
}
