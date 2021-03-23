/*
** EPITECH PROJECT, 2021
** range tower
** File description:
** make the towers work
*/

#include <../include/my.h>

void e2v2rangetowert1(all *a, int i)
{
    pos p;
    for (int y = 0; y < a->nb_enemy2; ++y) {
        e2defpos(&p, a, i, y);
        if (p.postx <  p.pos1x + 150 && p.postx >  p.pos1x - 250) {
            if (p.posty < p.pos1y + 150 && p.posty >  p.pos1y - 250) {
                if (a->enemy2[y].hp > 0) {
                    sfMusic_play(a->shoot[rande(4, 0)]);
                    a->enemy2[y].hp -= 1;
                    a->enemy2[y].hitted = true;
                    break;
                }
            }
        }
    }
}

void e2v3rangetowert2(all *a, int y , int i)
{
    if (a->enemy2[y].hp > 0 && a->turret2[i].hp > 0) {
        a->turret2[i].hp -= 1;
        a->enemy2[y].hp -= 2;
        a->enemy2[y].hitted = true;
    }
}

void e2v2rangetowert2(all *a, int i)
{
    int pos1x;
    int postx;
    int pos1y;
    int posty;
    for (int y = 0; y < a->nb_enemy2; ++y) {
        pos1x = a->turret2[i].position.x;
        postx = a->enemy2[y].xy.x - 50;
        pos1y = a->turret2[i].position.y;
        posty = a->enemy2[y].xy.y - 50;
        if (postx <  pos1x + 50 && postx >  pos1x - 150) {
            if (posty < pos1y + 50 && posty >  pos1y - 150)
                v3rangetowert2(a, y, i);
        }
    }
}

void e2v2rangetowert3(all *a, int i)
{
    int pos1x;
    int postx;
    int pos1y;
    int posty;
    for (int y = 0; y < a->nb_enemy2; ++y) {
        pos1x = a->turret3[i].position.x;
        postx = a->enemy2[y].xy.x - 50;
        pos1y = a->turret3[i].position.y;
        posty = a->enemy2[y].xy.y - 50;
        if (postx <  pos1x + 150 && postx >  pos1x - 250) {
            if (posty < pos1y + 150 && posty >  pos1y - 250) {
                if (a->enemy2[y].hp > 0) {
                    sfMusic_play(a->explosion[rande(2, 0)]);
                    a->enemy2[y].hp -= 1;
                    a->enemy2[y].hitted = true;
                }
            }
        }
    }
}

void e2v2rangetowert4(all *a, int i)
{
    int pos1x;
    int postx;
    int pos1y;
    int posty;
    for (int y = 0; y < a->nb_enemy2; ++y) {
        pos1x = a->turret4[i].position.x + 150;
        postx = a->enemy2[y].xy.x - 50;
        pos1y = a->turret4[i].position.y + 150;
        posty = a->enemy2[y].xy.y - 50;
        if (postx <  pos1x && postx >  pos1x - 400) {
            if (posty < pos1y && posty >  pos1y - 400) {
                if (a->enemy2[y].hp > 0)
                    a->enemy2[y].speed = 1;
            }
        }
        else
            a->enemy2[y].speed = 1;
    }
}