/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

void meteor_2(cloud_t *meteor)
{
    meteor->pos.y = meteor->mv.y + sin(meteor->mv.x) * 80;
    meteor->mv.x++;
    if (meteor->mv.x == 360)
        meteor->mv.x = 0;
}

void meteor_5(sfml *all)
{
    cloud_t *meteor = all->sp->meteor;

    while (meteor != NULL) {
        if (sfClock_getElapsedTime(meteor->c_cloud).microseconds > 40000) {
            meteor->pos.y = meteor->mv.y + sin(meteor->mv.x) * 40;
        }
        sfSprite_setPosition(meteor->cloud, meteor->pos);
        sfRenderWindow_drawSprite(all->window, meteor->cloud, NULL);
        meteor = meteor->next;
    }
}

void meteor_3(sfml *all)
{
    cloud_t *meteor = all->sp->meteor;

    while (meteor != NULL) {
        if (sfClock_getElapsedTime(meteor->c_cloud).microseconds > 80000) {
            meteor_2(meteor);
            sfClock_restart(meteor->c_cloud);
        }
        sfSprite_setPosition(meteor->cloud, meteor->pos);
        sfRenderWindow_drawSprite(all->window, meteor->cloud, NULL);
        meteor = meteor->next;
    }
    meteor_5(all);
}
