/*
** EPITECH PROJECT, 2021
** putnbr
** File description:
** nothing
*/

void my_putchar(char c);

int my_put_long(long nb)
{
    int dcm = 1;

    if (nb > 4294967295 || nb < -4294967295)
        return -1;
    if (nb < 0)
        nb = 4294967295 - nb;
    while ((nb / dcm) >= 10)
        dcm = dcm * 10;
    while (dcm > 0) {
        my_putchar((nb / dcm) % 10 + 48);
        dcm = dcm / 10;
    }
    return 0;
}
