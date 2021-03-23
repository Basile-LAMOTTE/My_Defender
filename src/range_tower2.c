/*
** EPITECH PROJECT, 2021
** range tower
** File description:
** make the towers work
*/

#include <../include/my.h>

void defpos(pos *p, all *a, int i, int y)
{
    p->pos1x = a->turret1[i].position.x;
    p->postx = a->enemy1[y].xy.x - 50;
    p->pos1y = a->turret1[i].position.y;
    p->posty = a->enemy1[y].xy.y - 50;
}

void v2rangetowert1(all *a, int i)
{
    pos p;
    int rand = rande(4, 0);
    for (int y = 0; y < a->nb_enemy1; ++y) {
        defpos(&p, a, i, y);
        if (p.postx <  p.pos1x + 150 && p.postx >  p.pos1x - 250) {
            if (p.posty < p.pos1y + 150 && p.posty >  p.pos1y - 250) {
                sfMusic_stop(a->shoot[rand]);
                sfMusic_play(a->shoot[rand]);
                if (a->enemy1[y].hp > 0) {
                    a->enemy1[y].hp -= 1;
                    a->enemy1[y].hitted = true;
                    break;
                }
            }
        }
    }
    e2v2rangetowert1(a, i);
}

void v3rangetowert2(all *a, int y , int i)
{
    if (a->enemy1[y].hp > 0 && a->turret2[i].hp > 0) {
        a->turret2[i].hp -= 1;
        a->enemy1[y].hp -= 2;
        a->enemy1[y].hitted = true;
    }
}

void v2rangetowert2(all *a, int i)
{
    int pos1x;
    int postx;
    int pos1y;
    int posty;
    for (int y = 0; y < a->nb_enemy1; ++y) {
        pos1x = a->turret2[i].position.x;
        postx = a->enemy1[y].xy.x - 50;
        pos1y = a->turret2[i].position.y;
        posty = a->enemy1[y].xy.y - 50;
        if (postx <  pos1x + 50 && postx >  pos1x - 150) {
            if (posty < pos1y + 50 && posty >  pos1y - 50)
                    v3rangetowert2(a, y, i);
        }
    }
    e2v2rangetowert2(a, i);
}

void v2rangetowert3(all *a, int i)
{
    pos p;
    int rand = rande(3, 0);
    for (int y = 0; y < a->nb_enemy1; ++y) {
        defpos(&p, a, i, y);
        if (p.postx <  p.pos1x + 150 && p.postx >  p.pos1x - 250) {
            if (p.posty < p.pos1y + 150 && p.posty >  p.pos1y - 250) {
                if (a->enemy1[y].hp > 0) {
                    sfMusic_stop(a->explosion[rand]);
                    sfMusic_play(a->explosion[rand]);
                    a->enemy1[y].hp -= 1;
                    a->enemy1[y].hitted = true;
                }
            }
        }
    }
    e2v2rangetowert3(a, i);
}