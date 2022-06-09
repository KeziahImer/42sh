/*
** EPITECH PROJECT, 2021
** Printf
** File description:
** Pointeur's function
*/

#include "my.h"
#include <stdarg.h>

int p_my_putstr(va_list list)
{
    my_putstr(va_arg(list, char *));
    return 0;
}

int p_my_put_adress(va_list list)
{
    my_put_adress(va_arg(list, long long));
    return 0;
}

int p_my_put_hexa_upper(va_list list)
{
    my_put_hexa_upper(va_arg(list, unsigned int));
    return 0;
}

int p_my_put_hexa_low(va_list list)
{
    my_put_hexa_low(va_arg(list, unsigned int));
    return 0;
}

int p_my_put_oct(va_list list)
{
    my_put_oct(va_arg(list, unsigned int));
    return 0;
}
