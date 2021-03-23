/*
** EPITECH PROJECT, 2021
** rotate
** File description:
** rotate the enemy sprite
*/

#include <../include/my.h>

void v2totatey(all *a, int i)
{
    if (a->enemy1[i].route == 4 && a->enemy1[i].decal == 4) {
        a->enemy1[i].decal = 5;
        a->enemy1[i].xy.x -= 30;
        a->enemy1[i].xy.y -= 70;
    }
    if (a->enemy1[i].route == 5 && a->enemy1[i].decal == 5) {
        a->enemy1[i].decal = 6;
        a->enemy1[i].xy.y -= 40;
        a->enemy1[i].xy.x += 40;
    }
    if (a->enemy1[i].route == 6 && a->enemy1[i].decal == 6) {
        a->enemy1[i].decal = 7;
        a->enemy1[i].xy.x -= 40;
        a->enemy1[i].xy.y -= 10;
    }
    if (a->enemy1[i].route == 7 && a->enemy1[i].decal == 7) {
        a->enemy1[i].decal = 8;
        a->enemy1[i].xy.y += 70;
    }
}

void v2totatey2(all *a, int i)
{
    if (a->enemy2[i].route == 4 && a->enemy2[i].decal == 4) {
        a->enemy2[i].decal = 5;
        a->enemy2[i].xy.x -= 30;
        a->enemy2[i].xy.y -= 70;
    }
    if (a->enemy2[i].route == 5 && a->enemy2[i].decal == 5) {
        a->enemy2[i].decal = 6;
        a->enemy2[i].xy.y -= 40;
        a->enemy2[i].xy.x += 40;
    }
    if (a->enemy2[i].route == 6 && a->enemy2[i].decal == 6) {
        a->enemy2[i].decal = 7;
        a->enemy2[i].xy.x -= 40;
        a->enemy2[i].xy.y -= 10;
    }
    if (a->enemy2[i].route == 7 && a->enemy2[i].decal == 7) {
        a->enemy2[i].decal = 8;
        a->enemy2[i].xy.y += 70;
    }
}

void rotatey(all *a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if (a->enemy1[i].route == 1 && a->enemy1[i].decal == 1) {
            a->enemy1[i].decal = 2;
            a->enemy1[i].xy.y += 70;
        }
        if (a->enemy1[i].route == 2 && a->enemy1[i].decal == 2) {
            a->enemy1[i].decal = 3;
            a->enemy1[i].xy.x += 70;
        }
        if (a->enemy1[i].route == 3 && a->enemy1[i].decal == 3) {
            a->enemy1[i].decal = 4;
            a->enemy1[i].xy.x -= 70;
        }
        v2totatey(a, i);
    }
}

void rotatey2(all *a)
{
    for (int i = 0; i < a->nb_enemy2; ++i) {
        if (a->enemy2[i].route == 1 && a->enemy2[i].decal == 1) {
            a->enemy2[i].decal = 2;
            a->enemy2[i].xy.y += 70;
        }
        if (a->enemy2[i].route == 2 && a->enemy2[i].decal == 2) {
            a->enemy2[i].decal = 3;
            a->enemy2[i].xy.x += 70;
        }
        if (a->enemy2[i].route == 3 && a->enemy2[i].decal == 3) {
            a->enemy2[i].decal = 4;
            a->enemy2[i].xy.x -= 70;
        }
        v2totatey2(a, i);
    }
}

void rotate_enemy1(all *a)
{
    rotatey(a);
    for (int x = 0; x < a->nb_enemy1; ++x) {
        if (a->enemy1[x].route == 1)
            sfSprite_setRotation(a->enemy1[x].sprite, 270);
        if (a->enemy1[x].route == 2)
            sfSprite_setRotation(a->enemy1[x].sprite, 180);
        if (a->enemy1[x].route == 3)
            sfSprite_setRotation(a->enemy1[x].sprite, 270);
        if (a->enemy1[x].route == 4)
            sfSprite_setRotation(a->enemy1[x].sprite, 0);
        if (a->enemy1[x].route == 5)
            sfSprite_setRotation(a->enemy1[x].sprite, 90);
        if (a->enemy1[x].route == 6)
            sfSprite_setRotation(a->enemy1[x].sprite, 0);
        if (a->enemy1[x].route == 7)
            sfSprite_setRotation(a->enemy1[x].sprite, 270);
    }
}