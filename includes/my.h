/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** yolo
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <math.h>
    #include <sys/signal.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/SoundStatus.h>
    #include "struct.h"
    #define MAX(x, y)   (((x) < (y)) ? (y) : (x))
    #define MIN(x, y)   (((x) > (y)) ? (y) : (x))
    #define ABS(x)   ((x) >= 0 ? (x) : (-x))
    #define ABS_ADD(x, i)   ((x) >= 0 ? (x + i) : (x - i))

//basic fcts
void my_putstr(char const *str);
char *my_strdupcat(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *int_to_str(int nb);

//sfml fcts
void init(sfml *all);
void cloack(sfml *all);
void init_perso_l(sfml *all);
void init_perso(sfml *all);
void init_perso_jump(sfml *all);
void jump(sfml *all);
void init_map(sfml *all);
void init_map_2(sfml *all);
int charg_map(char **av, sfml *all);
void cloud(sfml *all);
int check_if_ground(sfml *all);
void end_jump(sfml *all);
void gravity(sfml *all);
void background(sfml *all);
int menu(sfml *all, char **av);
void help(void);
void score(sfml *all);
void victory(sfml *all);
void defeat(sfml *all);
void meteor_3(sfml *all);
void death(sfml *all);
void water(sfml *all);
void pause_wait(sfml *all);
void disp(sfml *all, char *name, sfVector2f pos, sfVector2f rect);

#endif
