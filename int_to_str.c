/*
** EPITECH PROJECT, 2022
** int_to_str
** File description:
** convert an int into a str
*/

#include "my.h"

int intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *int_to_str(int nb)
{
    int len = intlen(nb);
    char *nbr = malloc(sizeof(char) * (len + 1));

    nbr[len] = '\0';
    len--;
    for (; len >= 0; len--) {
        nbr[len] = nb % 10 + 48;
        nb = nb / 10;
    }
    return (nbr);
}
