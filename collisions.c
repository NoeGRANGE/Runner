/*
** EPITECH PROJECT, 2021
** check collisions
** File description:
** check if there is a collision betweeen player and object like plateform
** or obstacles
*/

#include "my.h"

int meteor_death(sfml *all)
{
    cloud_t *tmp;

    if (all->meteor == 0)
        return (0);
    tmp = all->sp->meteor;
    while (tmp != NULL) {
        if (((all->pos.x >= tmp->pos.x + 20 &&
        all->pos.x <= tmp->pos.x + 175) ||
        (all->pos.x + 100 >= tmp->pos.x + 20 &&
        all->pos.x + 100 <= tmp->pos.x + 175)) &&
        ((all->pos.y >= tmp->pos.y + 20 && all->pos.y <= tmp->pos.y + 167) ||
        (all->pos.y + 164 >= tmp->pos.y + 20 &&
        all->pos.y + 164 <= tmp->pos.y + 167) || (all->pos.y + 50 >=
        tmp->pos.y + 20 && all->pos.y + 50 <= tmp->pos.y + 167))) {
            all->dead_by_meteor = 1;
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int jump_before(sfml *all, cloud_t *tmp)
{
    if (meteor_death(all) == 1)
        return (1);
    if (tmp->type == 'C') {
        victory(all);
        return (1);
    }
    if (all->jump != 0)
        end_jump(all);
    return (0);
}

int check_if_ground(sfml *all)
{
    cloud_t *tmp = all->sp->cloud;

    all->ground = 0;
    while (tmp != NULL) {
        if (((all->pos.x + 35 >= tmp->pos.x &&
        all->pos.x + 35 <= tmp->pos.x + 220) ||
        (all->pos.x + 100 >= tmp->pos.x &&
        all->pos.x + 100 <= tmp->pos.x + 220)) &&
        all->pos.y + 164 >= tmp->pos.y + 5 &&
        all->pos.y + 164 <= tmp->pos.y + 35 &&
        (all->jump == 0 || all->jump > 9)) {
            all->ground = 1;
            return (jump_before(all, tmp));
        }
        tmp = tmp->next;
    }
    return (meteor_death(all));
}
