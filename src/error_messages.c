/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Error Messages
*/

#include <unistd.h>

static void write_seg(char *name)
{
    write(2, "Segmentation fault\n", 20);
}

static void write_floating(char *name)
{
    write(2, "Floating exception\n", 20);
}

void write_error_message(char *name, int status)
{
    int flags[2] = {8, 11};
    void (*ptr[2])(char *) = {write_floating, write_seg};

    for (int i = 0; i < 2; i++) {
        if (flags[i] == status)
            ptr[i](name);
    }
}
