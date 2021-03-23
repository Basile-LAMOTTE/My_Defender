/*
** EPITECH PROJECT, 2021
** other init
** File description:
** other int
*/

#include <../include/my.h>

void update_frame2(all *a, int i)
{
    if (a->enemy2[i].x == 0)
        a->enemy2[i].frame.left += 100;
    if (a->enemy2[i].x == 1)
        a->enemy2[i].frame.left -= 100;
    if (a->enemy2[i].frame.left >= 400)
        a->enemy2[i].x = 1;
    if (a->enemy2[i].frame.left <= 0)
        a->enemy2[i].x = 0;

    if (a->enemy2[i].hitted == true) {
        a->enemy2[i].frame.left = 500;
        a->enemy2[i].hitted = false;
    }
}

void update_enemy1(all *a)
{

    for (int i = 0; i < a->nb_enemy1; ++i) {
        a->enemy1[i].time = sfClock_getElapsedTime(a->enemy1[i].clock);
        float sec = a->enemy1[i].time.microseconds / 1000000.0;
        if (sec > 0.01) {
            update_frame(a, i);
            sfClock_restart(a->enemy1[i].clock);
            sfSprite_setTextureRect(a->enemy1[i].sprite, a->enemy1[i].frame);
        }
        rotate_enemy1(a);
        sfSprite_setPosition(a->enemy1[i].sprite, a->enemy1[i].xy);
    }
}

void update_enemy2(all *a)
{
    for (int i = 0; i < a->nb_enemy2; ++i) {
        a->enemy2[i].time = sfClock_getElapsedTime(a->enemy2[i].clock);
        float sec = a->enemy2[i].time.microseconds / 1000000.0;
        if (sec > 0.02) {
            update_frame2(a, i);
            sfClock_restart(a->enemy2[i].clock);
            sfSprite_setTextureRect(a->enemy2[i].sprite, a->enemy2[i].frame);
        }
        rotate_enemy2(a);
        sfSprite_setPosition(a->enemy2[i].sprite, a->enemy2[i].xy);
    }
}