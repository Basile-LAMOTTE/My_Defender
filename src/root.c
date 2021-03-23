/*
** EPITECH PROJECT, 2021
** root
** File description:
** root functions
*/

#include <../include/my.h>

void root3(all* a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if (a->enemy1[i].route == 6) {
            if (a->enemy1[i].xy.y > 826)
                a->enemy1[i].route = 7;
            else
                a->enemy1[i].xy.y += 3 * a->enemy1[i].speed;
        }
        if (a->enemy1[i].route == 7) {
            if (a->enemy1[i].xy.x > 1600)
                a->enemy1[i].route = 8;
            else
                a->enemy1[i].xy.x += 3 * a->enemy1[i].speed;
        }
    }
}

void v2root2(all *a, int i)
{
    if (a->enemy1[i].route == 5) {
        if (a->enemy1[i].xy.x < 890)
            a->enemy1[i].route = 6;
        else
            a->enemy1[i].xy.x -= 3 * a->enemy1[i].speed;
    }
}

void root2(all* a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if (a->enemy1[i].route == 3) {
            if (a->enemy1[i].xy.x > 1200)
                a->enemy1[i].route = 4;
            else
                a->enemy1[i].xy.x += 3 * a->enemy1[i].speed;
        }
        if (a->enemy1[i].route == 4) {
            if (a->enemy1[i].xy.y > 575)
                a->enemy1[i].route = 5;
            else
                a->enemy1[i].xy.y += 3 * a->enemy1[i].speed;
        }
        v2root2(a, i);
    }
    root3(a);
}

void v2root(all *a, int i)
{
    if (a->enemy1[i].route == 2) {
        if (a->enemy1[i].xy.y < 200)
            a->enemy1[i].route = 3;
        else
            a->enemy1[i].xy.y -= 3 * a->enemy1[i].speed;
    }
}

void root(all *a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if (a->enemy1[i].route == 0) {
            if (a->enemy1[i].xy.y > 820) {
                a->enemy1[i].route = 1;
            }
            else {
                a->enemy1[i].xy.y += 3 * a->enemy1[i].speed;
            }
        }
        if (a->enemy1[i].route == 1) {
            if (a->enemy1[i].xy.x > 440)
                a->enemy1[i].route = 2;
            else
                a->enemy1[i].xy.x += 3 * a->enemy1[i].speed;
        }
        v2root(a, i);
    }
    root2(a);
}