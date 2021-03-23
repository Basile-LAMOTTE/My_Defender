/*
** EPITECH PROJECT, 2021
** r22t
** File description:
** r22t functions
*/

#include <../include/my.h>

void r22t3(all* a)
{
    for (int i = 0; i < a->nb_enemy2; ++i) {
        if (a->enemy2[i].route == 6) {
            if (a->enemy2[i].xy.y > 826)
                a->enemy2[i].route = 7;
            else
                a->enemy2[i].xy.y += 3 * a->enemy2[i].speed;
        }
        if (a->enemy2[i].route == 7) {
            if (a->enemy2[i].xy.x > 1600)
                a->enemy2[i].route = 8;
            else
                a->enemy2[i].xy.x += 3 * a->enemy2[i].speed;
        }
    }
}

void v2r22t2(all *a, int i)
{
    if (a->enemy2[i].route == 5) {
        if (a->enemy2[i].xy.x < 890)
            a->enemy2[i].route = 6;
        else
            a->enemy2[i].xy.x -= 3 * a->enemy2[i].speed;
    }
}

void r22t2(all* a)
{
    for (int i = 0; i < a->nb_enemy2; ++i) {
        if (a->enemy2[i].route == 3) {
            if (a->enemy2[i].xy.x > 1200)
                a->enemy2[i].route = 4;
            else
                a->enemy2[i].xy.x += 3 * a->enemy2[i].speed;
        }
        if (a->enemy2[i].route == 4) {
            if (a->enemy2[i].xy.y > 575)
                a->enemy2[i].route = 5;
            else
                a->enemy2[i].xy.y += 3 * a->enemy2[i].speed;
        }
        v2r22t2(a, i);
    }
    r22t3(a);
}

void v2r22t(all *a, int i)
{
    if (a->enemy2[i].route == 2) {
        if (a->enemy2[i].xy.y < 200)
            a->enemy2[i].route = 3;
        else
            a->enemy2[i].xy.y -= 3 * a->enemy2[i].speed;
    }
}

void r22t(all *a)
{
    for (int i = 0; i < a->nb_enemy2; ++i) {
        if (a->enemy2[i].route == 0) {
            if (a->enemy2[i].xy.y > 820) {
                a->enemy2[i].route = 1;
            }
            else {
                a->enemy2[i].xy.y += 3 * a->enemy2[i].speed;
            }
        }
        if (a->enemy2[i].route == 1) {
            if (a->enemy2[i].xy.x > 440)
                a->enemy2[i].route = 2;
            else
                a->enemy2[i].xy.x += 3 * a->enemy2[i].speed;
        }
        v2r22t(a, i);
    }
    r22t2(a);
}