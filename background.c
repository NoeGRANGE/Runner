/*
** EPITECH PROJECT, 2021
** background
** File description:
** create the background
*/

#include "my.h"

char *name_water(sfml *all)
{
    char *str = malloc(sizeof(char) * 31);
    char * nbr = malloc(sizeof(char) * 3);

    str[0] = '\0';
    str = my_strcat(str, "sprites/pirate_WaterA_00");
    nbr[0] = all->water / 10 + 48;
    nbr[1] = all->water % 10 + 48;
    nbr[2] = '\0';
    str = my_strcat(str, nbr);
    str = my_strcat(str, ".png");
    return (str);
}

void water(sfml *all)
{
    sfVector2f rect = {1.9 , 1.9};
    char *str = name_water(all);

    if (sfClock_getElapsedTime(all->cl->water).microseconds > 50000) {
        all->water++;
        if (all->water == 51)
            all->water = 1;
        sfClock_restart(all->cl->water);
    }
    all->sp->t_background = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(all->sp->background, all->sp->t_background, sfTrue);
    sfSprite_setScale(all->sp->background, rect);
    free(str);
}

void sky(sfml *all, back_t *back)
{
    if (sfClock_getElapsedTime(back->c_back).microseconds > 60000) {
        back->pos.x -= back->mv;
        if (back->pos.x <= -1920)
            back->pos.x = 1920;
        sfClock_restart(back->c_back);
    }
    sfSprite_setPosition(back->back, back->pos);
    sfRenderWindow_drawSprite(all->window, back->back, NULL);
}

void background_2(sfml *all)
{
    back_t *back_4 = all->cloud_3;

    for (int i = 0; i < 2; i++) {
        sky(all, back_4);
        back_4 = back_4->next;
    }
    water(all);
}

void background(sfml *all)
{
    back_t *back = all->sky;
    back_t *back_2 = all->cloud_1;
    back_t *back_3 = all->cloud_2;

    for (int i = 0; i < 2; i++) {
        sky(all, back);
        back = back->next;
    }
    for (int i = 0; i < 2; i++) {
        sky(all, back_2);
        back_2 = back_2->next;
    }
    for (int i = 0; i < 2; i++) {
        sky(all, back_3);
        back_3 = back_3->next;
    }
    background_2(all);
}
