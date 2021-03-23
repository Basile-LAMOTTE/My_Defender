/*
** EPITECH PROJECT, 2021
** other init
** File description:
** other int
*/

#include <../include/my.h>

button_t init_background(char *file)
{
    button_t background = {0};
    background.texture = sfTexture_createFromFile(file, NULL);
    background.sprite = sfSprite_create();
    sfSprite_setTexture(background.sprite, background.texture, sfTrue);
    return (background);
}

void v2init_enemy1(all *a, int i)
{
    a->enemy1[i].texture = sfTexture_createFromFile("texture/Enemy1.png" ,
                                                    NULL);
}

void v2init_enemy(all *a, int i)
{
    a->enemy1[i].alive = true;
    a->enemy1[i].y = 0;
    a->enemy1[i].x = 0;
    a->enemy1[i].decal = 1;
    a->enemy1[i].speed = 2;
    a->enemy1[i].clock = sfClock_create();
    v2init_enemy1(a, i);
    a->enemy1[i].sprite = sfSprite_create();
    sfSprite_setTexture(a->enemy1[i].sprite, a->enemy1[i].texture, sfTrue);
}

void rotate_enemy2(all *a)
{
    rotatey2(a);
    for (int x = 0; x < a->nb_enemy2; ++x) {
        if (a->enemy2[x].route == 1)
            sfSprite_setRotation(a->enemy2[x].sprite, 270);
        if (a->enemy2[x].route == 2)
            sfSprite_setRotation(a->enemy2[x].sprite, 180);
        if (a->enemy2[x].route == 3)
            sfSprite_setRotation(a->enemy2[x].sprite, 270);
        if (a->enemy2[x].route == 4)
            sfSprite_setRotation(a->enemy2[x].sprite, 0);
        if (a->enemy2[x].route == 5)
            sfSprite_setRotation(a->enemy2[x].sprite, 90);
        if (a->enemy2[x].route == 6)
            sfSprite_setRotation(a->enemy2[x].sprite, 0);
        if (a->enemy2[x].route == 7)
            sfSprite_setRotation(a->enemy2[x].sprite, 270);
    }
}