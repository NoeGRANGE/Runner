/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu of the game
*/

#include "my.h"

int menu_2(sfml *all, char **av)
{
    sfText *start = sfText_create();

    sfText_setFont(start, sfFont_createFromFile("sprites/font.ttf"));
    sfText_setString(start, "START");
    sfText_setColor(start, sfBlack);
    sfText_setCharacterSize(start, 100);
    sfText_setPosition(start, (sfVector2f) {800, 450});
    sfRenderWindow_drawText(all->window, start, NULL);
    all->meteor = 0;
    if (charg_map(av, all) == 84)
        return (84);
    if (all->meteor != 0)
        all->meteor = 1;
    return (0);
}

int menu(sfml *all, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f rect = {1.5, 1.5};

    all->window = sfRenderWindow_create(mode, "Cup Head", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(all->window, 30);
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_display(all->window);
    all->sp = malloc(sizeof(sp_t));
    all->screen = 0;
    all->sp->cuphead = sfSprite_create();
    all->sp->t_cuphead = sfTexture_createFromFile("sprites/cuphead.png", NULL);
    sfSprite_setTexture(all->sp->cuphead, all->sp->t_cuphead, sfTrue);
    sfSprite_setScale(all->sp->cuphead, rect);
    sfRenderWindow_drawSprite(all->window, all->sp->cuphead, NULL);
    if (menu_2(all, av) == 84)
        return (84);
    sfRenderWindow_display(all->window);
    return (0);
}

void pause_wait(sfml *all)
{
    sfText *stop = sfText_create();

    all->screen = 6;
    disp(all, "sprites/board.png", (sfVector2f) {580, 300},
    (sfVector2f) {1.3, 1.3});
    sfText_setFont(stop, sfFont_createFromFile("sprites/font.ttf"));
    sfText_setColor(stop, sfWhite);
    sfText_setCharacterSize(stop, 150);
    sfText_setPosition(stop, (sfVector2f) {750, 450});
    sfText_setString(stop, "PAUSE");
    sfRenderWindow_drawText(all->window, stop, NULL);
    sfRenderWindow_display(all->window);
}
