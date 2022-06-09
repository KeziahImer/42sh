/*
** EPITECH PROJECT, 2021
** Day 06
** File description:
** nothing
*/

int my_strlen(char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int a = my_strlen(dest);

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (a < n) {
        while (i < n) {
            dest[i] = '\0';
            i++;
        }
    }
    return (dest);
}
