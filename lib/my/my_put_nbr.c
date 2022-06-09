/*
** EPITECH PROJECT, 2021
** putnbr
** File description:
** nothing
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int dcm = 1;

    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while ((nb / dcm) >= 10)
        dcm = dcm * 10;
    while (dcm > 0) {
        my_putchar((nb / dcm) % 10 + 48);
        dcm = dcm / 10;
    }
    return (0);
}
