/*
** EPITECH PROJECT, 2021
** Printf
** File description:
** Pointer's function
*/

#include "my.h"
#include <stdarg.h>

int p_my_put_bin(va_list list)
{
    my_put_bin(va_arg(list, unsigned int));
    return 0;
}

int p_my_put_invis(va_list list)
{
    my_put_invis(va_arg(list, char *));
    return 0;
}

int p_my_put_long(va_list list)
{
    my_put_long(va_arg(list, long));
    return 0;
}

int p_my_put_nbr(va_list list)
{
    my_put_nbr(va_arg(list, int));
    return 0;
}

int p_my_putchar(va_list list)
{
    my_putchar(va_arg(list, int));
    return 0;
}
