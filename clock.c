/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

void run(sfml *all)
{
    if (sfClock_getElapsedTime(all->cl->run).microseconds > 20000) {
        all->pos.x += 20;
        if (all->jump != 0) {
            sfClock_restart(all->cl->run);
            return;
        }
        all->anim.top = 0;
        all->anim.left += 135;
        if (all->anim.left == 2430)
            all->anim.left = 270;
        all->anim.width = 135;
        all->anim.height = 164;
        sfClock_restart(all->cl->run);
    }
    sfSprite_setPosition(all->sp->perso, all->pos);
    sfSprite_setTextureRect(all->sp->perso, all->anim);
}

void run_l(sfml *all)
{
    if (sfClock_getElapsedTime(all->cl->run).microseconds > 20000) {
        all->pos.x -= 22;
        if (all->jump != 0) {
            sfClock_restart(all->cl->run);
            return;
        }
        all->anim.top = 0;
        all->anim.left -= 135;
        if (all->anim.left == 0)
            all->anim.left = 2160;
        all->anim.width = 135;
        all->anim.height = 164;
        sfClock_restart(all->cl->run);
    }
    sfSprite_setPosition(all->sp->perso, all->pos);
    sfSprite_setTextureRect(all->sp->perso, all->anim);
}

void cloack(sfml *all)
{
    if (all->sound_on != 0 || all->screen == 6)
        return;
    sfRenderWindow_clear(all->window, sfBlack);
    background(all);
    sfRenderWindow_drawSprite(all->window, all->sp->background, NULL);
    if (check_if_ground(all) == 1)
        return;
    gravity(all);
    if (all->run == 1)
        run(all);
    if (all->run == 2)
        run_l(all);
    if (all->jump != 0)
        jump(all);
    cloud(all);
    sfRenderWindow_drawSprite(all->window, all->sp->perso, NULL);
    sfRenderWindow_drawSprite(all->window, all->sp->esc, NULL);
    score(all);
    sfRenderWindow_display(all->window);
}
