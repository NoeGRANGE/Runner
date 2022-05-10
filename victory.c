/*
** EPITECH PROJECT, 2022
** victory
** File description:
** display all the elements of victory
*/

#include "my.h"

void disp(sfml *all, char *name, sfVector2f pos, sfVector2f rect)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *t_sprite = sfTexture_createFromFile(name, NULL);

    sfSprite_setTexture(sprite, t_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, rect);
    sfRenderWindow_drawSprite(all->window, sprite, NULL);
}

void victory(sfml *all)
{
    disp(all, "sprites/win.png", (sfVector2f) {0, 0},
    (sfVector2f) {1.25, 0.7});
    disp(all, "sprites/board.png", (sfVector2f) {580, 300},
    (sfVector2f) {1.3, 1.3});
    disp(all, "sprites/results.png", (sfVector2f) {550, 180},
    (sfVector2f) {1, 1});
    disp(all, "sprites/star.png", (sfVector2f) {1200, 300},
    (sfVector2f) {2, 2});
    disp(all, "sprites/cup_win.png", (sfVector2f) {400, 450},
    (sfVector2f) {1, 1});
    sfText_setCharacterSize(all->score, 150);
    sfText_setPosition(all->score, (sfVector2f) {750, 450});
    sfText_setColor(all->score, sfYellow);
    sfRenderWindow_drawText(all->window, all->score, NULL);
    all->screen = 2;
    sfRenderWindow_display(all->window);
}

void defeat(sfml *all)
{
    disp(all, "sprites/win.png", (sfVector2f) {0, 0},
    (sfVector2f) {1.25, 0.7});
    disp(all, "sprites/board.png", (sfVector2f) {580, 300},
    (sfVector2f) {1.3, 1.3});
    disp(all, "sprites/results.png", (sfVector2f) {550, 180},
    (sfVector2f) {1, 1});
    disp(all, "sprites/cup_defeat.png", (sfVector2f) {400, 450},
    (sfVector2f) {1, 1});
    sfText_setCharacterSize(all->score, 150);
    sfText_setPosition(all->score, (sfVector2f) {750, 450});
    sfText_setColor(all->score, sfRed);
    sfRenderWindow_drawText(all->window, all->score, NULL);
    all->screen = 2;
    sfRenderWindow_display(all->window);
}
