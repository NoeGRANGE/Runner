/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

void init_perso_jump(sfml *all)
{
    all->sp->t_perso = sfTexture_createFromFile("sprites/p_jump.png", NULL);
    all->sp->perso = sfSprite_create();
    all->anim.top = 0;
    all->anim.left = 0;
    all->anim.width = 88;
    all->anim.height = 109;
    all->jump = 1;
    sfSprite_setTexture(all->sp->perso, all->sp->t_perso, sfTrue);
    sfSprite_setPosition(all->sp->perso, all->pos);
    sfSprite_setTextureRect(all->sp->perso, all->anim);
}

void init_perso_l(sfml *all)
{
    all->run = 2;
    if (all->jump != 0)
        return;
    all->sp->t_perso = sfTexture_createFromFile("sprites/p_run_l.png", NULL);
    all->sp->perso = sfSprite_create();
    all->anim.top = 0;
    all->anim.left = 2430;
    all->anim.width = 135;
    all->anim.height = 164;
    sfSprite_setTexture(all->sp->perso, all->sp->t_perso, sfTrue);
    sfSprite_setPosition(all->sp->perso, all->pos);
    sfSprite_setTextureRect(all->sp->perso, all->anim);
}

void init_perso(sfml *all)
{
    if (all->jump != 0)
        return;
    all->sp->t_perso = sfTexture_createFromFile("sprites/p_run.png", NULL);
    all->sp->perso = sfSprite_create();
    all->anim.top = 0;
    all->anim.left = 0;
    all->anim.width = 135;
    all->anim.height = 164;
    sfSprite_setTexture(all->sp->perso, all->sp->t_perso, sfTrue);
    sfSprite_setPosition(all->sp->perso, all->pos);
    sfSprite_setTextureRect(all->sp->perso, all->anim);
}
