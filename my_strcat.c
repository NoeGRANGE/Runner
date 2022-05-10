/*
** EPITECH PROJECT, 2021
** boom.c
** File description:
** baam
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_max = my_strlen(dest) + my_strlen(src);

    for (int i = 0; src[i]; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_max] = '\0';
    return dest;
}
