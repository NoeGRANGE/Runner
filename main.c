/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

void check_death(sfml *all)
{
    if (all->dead_by_meteor == 1 || (all->screen == 1 && all->pos.y > 900 &&
    all->sound_on == 0)) {
        all->dead_by_meteor = 2;
        sfSound_play(all->sound);
        all->sound_on = 1;
    }
    if (all->sound_on != 0 && all->sound_on < 50) {
        if (sfClock_getElapsedTime(all->cl->close).microseconds > 60000) {
            death(all);
            sfClock_restart(all->cl->close);
        }
        if (all->sound_on == 50)
            defeat(all);
    }
}

void close_window_game(sfml *all)
{
    if (all->event.type == sfEvtKeyPressed &&
    all->event.key.code == sfKeyRight && all->run != 1) {
        all->run = 1;
        init_perso(all);
    }
    if (all->event.type == sfEvtKeyPressed &&
    all->event.key.code == sfKeyLeft && all->run != 2)
        init_perso_l(all);
    if (all->event.type == sfEvtKeyPressed &&
    all->event.key.code == sfKeySpace && all->jump == 0)
        init_perso_jump(all);
}

void close_window(sfml *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(all->window);
        if (all->screen == 0 && all->event.type == sfEvtMouseButtonPressed &&
        all->event.mouseButton.x >= 800 && all->event.mouseButton.x <= 1150 &&
        all->event.mouseButton.y >= 450 && all->event.mouseButton.y <= 550)
            init(all);
        if (all->screen == 1)
            close_window_game(all);
        if (all->screen == 6 && all->event.type == sfEvtKeyPressed &&
        all->event.key.code == sfKeyEscape) {
            all->screen = 1;
            return;
        }
        if (all->screen == 1 && all->event.type == sfEvtKeyPressed &&
        all->event.key.code == sfKeyEscape)
            pause_wait(all);
    }
}

void free_struct(sfml *all)
{
    sfSound_stop(all->sound);
    sfSoundBuffer_destroy(all->buffer_sound);
    sfMusic_stop(all->music);
    sfSound_destroy(all->sound);
    sfMusic_destroy(all->music);
    sfRenderWindow_destroy(all->window);
    free(all);
}

int main(int ac, char **av)
{
    sfml *all = malloc(sizeof(sfml));

    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
        help();
        return (0);
    }
    if (menu(all, av) == 84)
        return (84);
    while (sfRenderWindow_isOpen(all->window)) {
        close_window(all);
        if (all->screen == 1)
            cloack(all);
        check_death(all);
    }
    free_struct(all);
    return (0);
}
