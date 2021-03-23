/*
** EPITECH PROJECT, 2021
** range tower
** File description:
** make the towers work
*/

#include <../include/my.h>

void rangetowert1(all *a)
{
    for (int i = 0; i < a->i1; i += 1) {
        a->turret1[i].time = sfClock_getElapsedTime(a->turret1[i].clock);
        float sec = a->turret1[i].time.microseconds / 1000000.0;
        if (sec > 0.5) {
            v2rangetowert1(a, i);
            sfClock_restart(a->turret1[i].clock);
        }
    }
}

void rangetowert2(all *a)
{
    for (int i = 0; i < a->i2; i += 1) {
        a->turret2[i].time = sfClock_getElapsedTime(a->turret2[i].clock);
        float sec = a->turret2[i].time.microseconds / 1000000.0;
        if (sec > 0.5) {
            v2rangetowert2(a, i);
            sfClock_restart(a->turret2[i].clock);
        }
    }
}

void rangetowert3(all *a)
{
    for (int i = 0; i < a->i3; i += 1) {
        a->turret3[i].time = sfClock_getElapsedTime(a->turret3[i].clock);
        float sec = a->turret3[i].time.microseconds / 1000000.0;
        if (sec > 1) {
            v2rangetowert3(a, i);
            sfClock_restart(a->turret3[i].clock);
        }
    }
}

void rangetowert4(all *a)
{
    for (int i = 0; i < a->i4; i += 1) {
        a->turret4[i].time = sfClock_getElapsedTime(a->turret4[i].clock);
        float sec = a->turret4[i].time.microseconds / 1000000.0;
        if (sec > 0.5) {
            v2rangetowert4(a, i);
            sfClock_restart(a->turret4[i].clock);
        }
    }
}

void touchenemy(all *a)
{
    rangetowert1(a);
    rangetowert2(a);
    rangetowert3(a);
    rangetowert4(a);
    maingold(a);
}