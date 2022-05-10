/*
** EPITECH PROJECT, 2022
** score
** File description:
** update the score
*/

#include "my.h"

void score(sfml *all)
{
    if (sfClock_getElapsedTime(all->cl->scoreboard).microseconds > 80000) {
        sfText_setString(all->score, int_to_str(all->length));
        sfClock_restart(all->cl->scoreboard);
    }
    sfRenderWindow_drawText(all->window, all->score, NULL);
}
