/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of the screensaver
*/

#include "my.h"

back_t *create_back(sfml *all, sfVector2f pos, int mv, char *str)
{
    back_t *back = malloc(sizeof(back_t));

    back->back = sfSprite_create();
    back->c_back = sfClock_create();
    back->t_back = sfTexture_createFromFile(str, NULL);
    back->pos = pos;
    back->mv = mv;
    sfSprite_setTexture(back->back, back->t_back, sfTrue);
    sfSprite_setPosition(back->back, back->pos);
    sfRenderWindow_drawSprite(all->window, back->back, NULL);
    return (back);
}

void init_4(sfml * all)
{
    all->cl->scoreboard = sfClock_create();
    all->screen = 1;
    all->dead_by_meteor = 0;
    all->sp->t_esc = sfTexture_createFromFile("sprites/esc.png", NULL);
    all->sp->esc = sfSprite_create();
    sfSprite_setTexture(all->sp->esc, all->sp->t_esc, sfTrue);
    sfSprite_setScale(all->sp->esc, (sfVector2f) {2, 2});
    sfSprite_setPosition(all->sp->esc, (sfVector2f) {40, 40});
    sfRenderWindow_drawSprite(all->window, all->sp->esc, NULL);
}

void init_3(sfml * all)
{
    sfVector2f pos = {0, -10};
    sfVector2f pos_1 = {1920, -10};
    sfVector2f pos_2 = {0, 550};
    sfVector2f pos_3 = {1920, 550};

    all->sky = create_back(all, pos, 2, "sprites/sky.png");
    all->sky->next = create_back(all, pos_1, 2, "sprites/sky.png");
    all->sky->next->next = NULL;
    all->cloud_1 = create_back(all, pos_2, 3, "sprites/cloud_A.png");
    all->cloud_1->next = create_back(all, pos_3, 3, "sprites/cloud_A.png");
    all->cloud_1->next->next = NULL;
    all->cloud_2 = create_back(all, pos_2, 4, "sprites/cloud_B.png");
    all->cloud_2->next = create_back(all, pos_3, 4, "sprites/cloud_B.png");
    all->cloud_2->next->next = NULL;
    all->cloud_3 = create_back(all, pos_2, 5, "sprites/cloud_C.png");
    all->cloud_3->next = create_back(all, pos_3, 5, "sprites/cloud_C.png");
    all->cloud_3->next->next = NULL;
    init_4(all);
}

void init_2(sfml *all)
{
    sfVector2f pos_water = {0, 482};

    all->gravity = 1;
    all->water = 1;
    all->length = 0;
    all->score = sfText_create();
    sfText_setFont(all->score, sfFont_createFromFile("sprites/font.ttf"));
    sfText_setColor(all->score, sfBlack);
    sfText_setCharacterSize(all->score, 100);
    sfText_setPosition(all->score, (sfVector2f) {1600, 20});
    sfText_setString(all->score, "0");
    all->cl->gravity = sfClock_create();
    all->cl->water = sfClock_create();
    all->sp->background = sfSprite_create();
    sfSprite_setTexture(all->sp->background, all->sp->t_background, sfTrue);
    sfSprite_setPosition(all->sp->background, pos_water);
    sfRenderWindow_drawSprite(all->window, all->sp->background, NULL);
    sfRenderWindow_drawText(all->window, all->score, NULL);
    init_3(all);
}

void init(sfml *all)
{
    all->cl = malloc(sizeof(cl_t));
    all->run = 0;
    all->jump = 0;
    all->pos.y = 500;
    all->pos.x = 800;
    all->cl->run = sfClock_create();
    all->sp->t_background =
    sfTexture_createFromFile("sprites/pirate_WaterA_0001.png", NULL);
    init_2(all);
    init_perso(all);
    all->cl->close = sfClock_create();
    all->music = sfMusic_createFromFile("sprites/music.ogg");
    all->sound = sfSound_create();
    all->sound_on = 0;
    all->buffer_sound = sfSoundBuffer_createFromFile("sprites/sound.ogg");
    sfSound_setBuffer(all->sound, all->buffer_sound);
    sfMusic_play(all->music);
    sfMusic_getLoop(all->music);
    sfRenderWindow_display(all->window);
}
