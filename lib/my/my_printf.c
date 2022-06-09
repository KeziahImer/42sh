/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** main file
*/

#include <stdarg.h>
#include "my.h"

void redirection(char *flag, int (**ptr)(va_list), va_list list, char value)
{
    for (int i = 0; i < 12; i++) {
        if (flag[i] == value)
            ptr[i](list);
    }
}

int my_printf(char const *format, ...)
{
    int cpt = 0;
    va_list list;
    int (*ptr[12])(va_list) = {p_my_putchar, p_my_putstr,
        p_my_put_invis, p_my_put_nbr, p_my_put_nbr, p_my_put_long,
        p_my_put_bin, p_my_put_oct, p_my_put_hexa_low, p_my_put_hexa_upper,
        p_my_put_adress, p_my_put_pourcent};
    char flag[12] = {'c', 's', 'S', 'd', 'i', 'u', 'b', 'o', 'x',
        'X', 'p', '%'};

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++, cpt++) {
        if (format[i] == '%') {
            i++;
            redirection(flag, ptr, list, format[i]);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return cpt;
}
