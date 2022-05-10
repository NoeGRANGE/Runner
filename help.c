/*
** EPITECH PROJECT, 2022
** help
** File description:
** open the -h file
*/

#include "my.h"

void help(void)
{
    int file = open("h.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 428);

    read(file, buffer, 427);
    buffer[427] = '\0';
    my_putstr(buffer);
    free(buffer);
}
