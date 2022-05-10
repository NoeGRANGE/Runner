/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

void end_jump(sfml *all)
{
    all->jump = 0;
    if (all->run == 1 || all->run == 0) {
        init_perso(all);
        return;
    }
    if (all->run == 2)
        init_perso_l(all);
}

void jump(sfml *all)
{
    if (sfClock_getElapsedTime(all->cl->gravity).microseconds > 8000) {
        if (all->jump < 9) {
            all->pos.y -= 30;
        } else
            all->pos.y += 30;
        all->anim.top = 0;
        all->anim.left += 88;
        if (all->anim.left == 704)
            all->anim.left = 0;
        all->anim.width = 88;
        all->anim.height = 109;
        all->jump++;
        if (all->ground == 1)
            end_jump(all);
        sfClock_restart(all->cl->gravity);
    }
    sfSprite_setPosition(all->sp->perso, all->pos);
    sfSprite_setTextureRect(all->sp->perso, all->anim);
}

void gravity(sfml *all)
{
    if (all->ground == 1 || all->jump != 0)
        return;
    if (sfClock_getElapsedTime(all->cl->gravity).microseconds > 8000) {
        all->pos.y += 30;
        sfClock_restart(all->cl->gravity);
    }
    sfSprite_setPosition(all->sp->perso, all->pos);
}
