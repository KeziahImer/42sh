/*
** EPITECH PROJECT, 2021
** getnbr
** File description:
** nothing
*/

#include "my.h"
#include <stdlib.h>

int check_sign(char const *str)
{
    if (str[0] == '-')
        return -1;
    return 1;
}

int my_getnbr_index(char const *str, int i)
{
    int nb = 0;
    int sign = 0;

    if (str == NULL)
        return 0;
    sign = check_sign(str);
    if (sign == -1)
        i = 1;
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb = nb + (str[i] - 48);
    }
    nb = nb * sign;
    return nb;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int sign = 0;

    if (str == NULL)
        return 0;
    sign = check_sign(str);
    if (sign == -1)
        i = 1;
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb = nb + (str[i] - 48);
    }
    nb = nb * sign;
    return nb;
}

char *my_getstring(int result)
{
    int i = 0;
    int cpt = 1;
    int dcm = 1;
    char *str = NULL;

    for (; result / dcm >= 10; cpt++)
        dcm = dcm * 10;
    str = malloc(sizeof(char) * cpt + 1);
    for (; dcm > 0; i++, dcm /= 10)
        str[i] = ((result / dcm) % 10 + 48);
    str[i] = '\0';
    return str;
}
