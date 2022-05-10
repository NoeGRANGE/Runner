/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

char *name_meteor(sfml *all)
{
    char *str = malloc(sizeof(char) * 24);
    char * nbr = malloc(sizeof(char) * 2);

    str[0] = '\0';
    str = my_strcat(str, "sprites/meteor_000");
    nbr[0] = all->sp->meteor->type + 48;
    nbr[1] = '\0';
    str = my_strcat(str, nbr);
    str = my_strcat(str, ".png");
    return (str);
}

void meteor_4(cloud_t *meteor)
{
    if (meteor->type == 9)
        meteor->type = 1;
}

void meteor(sfml *all)
{
    cloud_t *meteor = all->sp->meteor;
    char *str = name_meteor(all);

    while (meteor != NULL) {
        if (sfClock_getElapsedTime(meteor->c_cloud).microseconds > 20000) {
            meteor->pos.x -= meteor->speed;
            meteor->type++;
            meteor_4(meteor);
        }
        sfSprite_setPosition(meteor->cloud, meteor->pos);
        meteor->t_cloud = sfTexture_createFromFile(str, NULL);
        sfSprite_setTexture(meteor->cloud, meteor->t_cloud, sfTrue);
        sfRenderWindow_drawSprite(all->window, meteor->cloud, NULL);
        meteor = meteor->next;
    }
    free(str);
    meteor_3(all);
}

void cloud(sfml *all)
{
    cloud_t *cloud = all->sp->cloud;

    while (cloud != NULL) {
        if (sfClock_getElapsedTime(cloud->c_cloud).microseconds > 20000) {
            cloud->pos.x -= 12;
            all->length += 1;
            sfClock_restart(cloud->c_cloud);
        }
        sfSprite_setPosition(cloud->cloud, cloud->pos);
        sfRenderWindow_drawSprite(all->window, cloud->cloud, NULL);
        cloud = cloud->next;
    }
    if (all->meteor != 0)
        meteor(all);
}
