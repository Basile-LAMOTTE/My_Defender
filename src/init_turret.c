/*
** EPITECH PROJECT, 2021
** intiturret
** File description:
** init the turrets
*/

#include <../include/my.h>

void init_turretv2(int i, char *str, button_t *turret)
{
    turret[i].texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(turret[i].sprite, turret[i].texture, sfTrue);
}

void init_turret1(all *a)
{
    for (int i = 0; i < 10; ++i) {
        a->turret1[i].clock = sfClock_create();
        a->turret1[i].sprite = sfSprite_create();
        init_turretv2(i, "texture/classicturret.png", a->turret1);
    }
}

void init_turret2(all *a)
{
    for (int i = 0; i < 10; ++i) {
        a->turret2[i].clock = sfClock_create();
        a->turret2[i].sprite = sfSprite_create();
        a->turret2[i].hp = 10;
        init_turretv2(i, "texture/spikes.png", a->turret2);
    }
}

void init_turret3(all *a)
{
    for (int i = 0; i < 10; ++i) {
        a->turret3[i].clock = sfClock_create();
        a->turret3[i].sprite = sfSprite_create();
        init_turretv2(i, "texture/bombturret.png", a->turret3);
    }
}

void init_turret4(all *a)
{
    for (int i = 0; i < 10; ++i) {
        a->turret4[i].clock = sfClock_create();
        a->turret4[i].sprite = sfSprite_create();
        init_turretv2(i, "texture/freezer.png", a->turret4);
    }
}