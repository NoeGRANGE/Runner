/*
** EPITECH PROJECT, 2022
** death
** File description:
** anim of death
*/

#include "my.h"

char *name_death(sfml *all)
{
    char *str = malloc(sizeof(char) * 28);
    char * nbr = malloc(sizeof(char) * 3);

    str[0] = '\0';
    str = my_strcat(str, "sprites/death_body_00");
    nbr[0] = all->sound_on / 10 + 48;
    nbr[1] = all->sound_on % 10 + 48;
    nbr[2] = '\0';
    str = my_strcat(str, nbr);
    str = my_strcat(str, ".png");
    return (str);
}

void back_death(sfml *all)
{
    cloud_t *meteor = all->sp->meteor;

    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawSprite(all->window, all->sky->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->sky->next->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud_1->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud_1->next->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud_2->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud_2->next->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud_3->back, NULL);
    sfRenderWindow_drawSprite(all->window, all->cloud_3->next->back, NULL);
    water(all);
    sfRenderWindow_drawSprite(all->window, all->sp->background, NULL);
    if (all->meteor == 0)
        return;
    while (meteor != NULL) {
        sfRenderWindow_drawSprite(all->window, meteor->cloud, NULL);
        meteor = meteor->next;
    }
}

void death(sfml *all)
{
    char *str = name_death(all);
    cloud_t *cloud = all->sp->cloud;

    all->sound_on++;
    back_death(all);
    while (cloud != NULL) {
        sfRenderWindow_drawSprite(all->window, cloud->cloud, NULL);
        cloud = cloud->next;
    }
    if (all->sound_on <= 17) {
        all->sp->t_perso = sfTexture_createFromFile(str, NULL);
        sfSprite_setTexture(all->sp->perso, all->sp->t_perso, sfTrue);
        sfRenderWindow_drawSprite(all->window, all->sp->perso, NULL);
    }
    sfRenderWindow_drawText(all->window, all->score, NULL);
    sfRenderWindow_display(all->window);
    free(str);
}
