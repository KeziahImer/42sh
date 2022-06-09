/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Error Handling
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int is_dir(char *str)
{
    int fd;
    struct stat sb;

    fd = open(str, O_RDONLY);
    if (fd == -1) {
        write(2, str, my_strlen(str));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
    stat(str, &sb);
    if (S_ISDIR(sb.st_mode) == 1) {
        write(2, str, my_strlen(str));
        write(2, ": Permission denied.\n", 22);
        return 1;
    }
    return 0;
}
