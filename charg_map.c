/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

int open_file_2(char **av, sfml *all, int file, char *buffer)
{
    int length = 1;

    while (length != 0) {
        length = read(file, buffer, 2);
        if (length < 0) {
            my_putstr("Runner: ");
            my_putstr(av[1]);
            write(2, ": Is a directory\n", 18);
            return (84);
        }
        buffer[length] = '\0';
        all->str_map = my_strdupcat(all->str_map, buffer);
    }
    return (0);
}

int open_file(char **av, sfml *all)
{
    char buffer[3];
    int file = open(av[1], O_RDONLY);

    if (file == -1) {
        my_putstr("Try to open: ");
        my_putstr(av[0]);
        write(2, ": No such file or directory\n", 29);
        return (84);
    }
    all->str_map = malloc(sizeof(char) * 1);
    all->str_map[0] = '\0';
    open_file_2(av, all, file, buffer);
    close(file);
    return (0);
}

int charg_map(char **av, sfml *all)
{
    if (open_file(av, all) == 84)
        return (84);
    init_map(all);
    init_map_2(all);
    return (0);
}
