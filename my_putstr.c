/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
