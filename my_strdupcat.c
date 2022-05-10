/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** fonction qui concatene 2 str
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return (len);
}

char *my_strdupcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *str = malloc(sizeof(char) * (dest_len + src_len + 1));
    int i;

    for (int j = 0; j < dest_len; j++) {
        str[j] = dest[j];
    }
    for (i = 0; src[i] != '\0'; i++) {
        str[dest_len + i] = src[i];
    }
    str[dest_len + i] = '\0';
    return (str);
}
