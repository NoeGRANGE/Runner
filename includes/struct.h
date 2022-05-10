/*
** EPITECH PROJECT, 2021
** struct
** File description:
** structure
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_
    #include <SFML/Graphics.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}framebuffer_t;

typedef struct cloud_t cloud_t;
struct cloud_t {
    sfSprite *cloud;
    sfTexture *t_cloud;
    sfClock *c_cloud;
    sfVector2f pos;
    sfVector2i mv;
    int type;
    int speed;
    cloud_t *next;
};

typedef struct back_t back_t;
struct back_t {
    sfSprite *back;
    sfTexture *t_back;
    sfClock *c_back;
    sfVector2f pos;
    int mv;
    back_t *next;
};

typedef struct sp_t {
    sfSprite *perso;
    sfTexture *t_perso;
    sfSprite *background;
    sfTexture *t_background;
    sfSprite *cuphead;
    sfTexture *t_cuphead;
    sfSprite *esc;
    sfTexture *t_esc;
    cloud_t *cloud;
    cloud_t *meteor;
}sp_t;

typedef struct cl_t {
    sfClock *run;
    sfClock *gravity;
    sfClock *water;
    sfClock *close;
    sfClock *scoreboard;
}cl_t;

typedef struct sfml {
    sfRenderWindow *window;
    sfEvent event;
    cl_t *cl;
    sp_t *sp;
    sfIntRect anim;
    sfIntRect a_water;
    sfVector2f pos;
    back_t *sky;
    back_t *cloud_1;
    back_t *cloud_2;
    back_t *cloud_3;
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer_sound;
    sfText *score;
    int sound_on;
    char *str_map;
    int screen;
    int run;
    int jump;
    int length;
    int gravity;
    int ground;
    int water;
    int meteor;
    int dead_by_meteor;
}sfml;

    #include "my.h"

#endif
