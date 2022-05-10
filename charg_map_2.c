/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

cloud_t *create_cloud(int x, int y, char c)
{
    cloud_t *cloud = malloc(sizeof(cloud_t));

    cloud->c_cloud = sfClock_create();
    cloud->cloud = sfSprite_create();
    cloud->t_cloud = sfTexture_createFromFile("sprites/cloud.png", NULL);
    cloud->pos.x = x * 240;
    cloud->pos.y = y * 160;
    cloud->mv.x = 0;
    cloud->mv.y = 0;
    cloud->type = c;
    sfSprite_setTexture(cloud->cloud, cloud->t_cloud, sfTrue);
    sfSprite_setPosition(cloud->cloud, cloud->pos);
    return (cloud);
}

cloud_t *create_meteor(sfml *all, int x, int y)
{
    cloud_t *meteor = malloc(sizeof(cloud_t));

    meteor->c_cloud = sfClock_create();
    meteor->cloud = sfSprite_create();
    meteor->t_cloud =
    sfTexture_createFromFile("sprites/meteor_0001.png", NULL);
    meteor->pos.x = x * 240;
    meteor->pos.y = y * 160;
    meteor->mv.x = 0;
    meteor->mv.y = y * 160;
    meteor->type = 1;
    meteor->speed = 10 + rand() % 10;
    sfSprite_setTexture(meteor->cloud, meteor->t_cloud, sfTrue);
    sfSprite_setPosition(meteor->cloud, meteor->pos);
    all->meteor++;
    return (meteor);
}

void init_map(sfml *all)
{
    cloud_t *cloud;
    int x = 0, y = 0, count = 0;

    for (int i = 0; all->str_map[i] != '\0'; i++) {
        if ((all->str_map[i] == 'c' || all->str_map[i] == 'C') && count == 1) {
            cloud->next = create_cloud(x, y, all->str_map[i]);
            cloud = cloud->next;
        }
        if (all->str_map[i] == 'c' && count == 0) {
            all->sp->cloud = create_cloud(x, y, all->str_map[i]);
            cloud = all->sp->cloud;
            count = 1;
        }
        x++;
        if (all->str_map[i] == '\n') {
            x = 0;
            y++;
        }
    }
    cloud->next = NULL;
}

void init_map_2(sfml *all)
{
    cloud_t *meteor;
    int x = 0, y = 0, count = 0;

    for (int i = 0; all->str_map[i] != '\0'; i++) {
        if (all->str_map[i] == 'm' && count == 1) {
            meteor->next = create_meteor(all, x, y);
            meteor = meteor->next;
        }
        if (all->str_map[i] == 'm' && count == 0) {
            all->sp->meteor = create_meteor(all, x, y);
            meteor = all->sp->meteor;
            count = 1;
        }
        x++;
        if (all->str_map[i] == '\n') {
            x = 0;
            y++;
        }
    }
    meteor->next = NULL;
}
