/*
** EPITECH PROJECT, 2021
** update enemy
** File description:
** update the enemy
*/

#include <../include/my.h>

void reset_enemies1(all *a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        a->enemy1[i].frame.width = 100;
        a->enemy1[i].frame.height = 100;
        a->enemy1[i].frame.top = 0;
        a->enemy1[i].frame.left = 0;
        a->enemy1[i].xy.y = 0;
        a->enemy1[i].xy.x = 140;
        a->enemy1[i].angle = 270;
        a->enemy1[i].route = 0;
        a->enemy1[i].hp = 3;
        a->enemy1[i].i = 0;
        a->enemy1[i].decal = 1;
        a->enemy1[i].alive = true;
        a->enemy1[i].hitted = false;
        a->enemy1[i].y = 0;
        a->enemy1[i].x = 0;
        a->enemy1[i].speed = 2;
        sfSprite_setRotation(a->enemy1[i].sprite, 0);
    }
}

void reset_enemies2(all *a)
{
    for (int i = 0; i < a->nb_enemy1; ++i) {
        a->enemy2[i].frame.width = 200;
        a->enemy2[i].frame.height = 200;
        a->enemy2[i].frame.top = 0;
        a->enemy2[i].frame.left = 0;
        a->enemy2[i].xy.y = 0;
        a->enemy2[i].xy.x = 240;
        a->enemy2[i].angle = 270;
        a->enemy2[i].route = 0;
        a->enemy2[i].hp = 10;
        a->enemy2[i].i = 0;
        a->enemy2[i].decal = 2;
        a->enemy1[i].alive = true;
        a->enemy2[i].hitted = false;
        a->enemy2[i].y = 0;
        a->enemy2[i].x = 0;
        a->enemy2[i].speed = 1;
        sfSprite_setRotation(a->enemy2[i].sprite, 0);
    }
}

void endWaveDetec(all *a)
{
    if (a->waveEnded == false) {
        a->waveEnded = true;
        for (int i = 0; i < a->nb_enemy1; ++i) {
            if (a->enemy1[i].hp > 0)
                a->waveEnded = false;
        }
        for (int i = 0; i < a->nb_enemy2; ++i) {
            if (a->enemy2[i].hp > 0)
                a->waveEnded = false;
        }
        if (a->waveEnded == true) {
            if (a->nb_enemy1 != 0)
                reset_enemies1(a);
            if (a->nb_enemy2 != 0)
                reset_enemies2(a);
            a->nb_enemy1 = 0;
            a->nb_enemy2 = 0;
        }
    }
}

void spawnenemi(all *a)
{
    endWaveDetec(a);
    if (a->waveEnded == true && a->nb_enemy1 + a->nb_enemy2*2 <= a->nb_wave*2) {
        a->time = sfClock_getElapsedTime(a->clock);
        float sec = a->time.microseconds / 1000000.0;
        if (sec > 0.1) {
            if (a->spawn > 0)
                --a->spawn;
            if (a->spawn == 0) {
                if (a->nb_wave % 5 == 0)
                    ++a->nb_enemy2;
                else
                    ++a->nb_enemy1;
                a->spawn = rande(10, 1);
            }
            sfClock_restart(a->clock);
        }
    }
    for (; a->waveEnded == true && a->nb_enemy1 == a->nb_wave*2; a->nb_wave++)
        a->waveEnded = false;
}

void update_frame(all *a, int i)
{
    if (a->enemy1[i].x == 0)
        a->enemy1[i].frame.left += 100;
    if (a->enemy1[i].x == 1)
        a->enemy1[i].frame.left -= 100;
    if (a->enemy1[i].frame.left >= 400)
        a->enemy1[i].x = 1;
    if (a->enemy1[i].frame.left <= 0)
        a->enemy1[i].x = 0;

    if (a->enemy1[i].hitted == true) {
        a->enemy1[i].frame.left = 500;
        a->enemy1[i].hitted = false;
    }
}
