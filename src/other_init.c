/*
** EPITECH PROJECT, 2021
** other init
** File description:
** other int
*/

#include <../include/my.h>

void init_enemy1(all *a)
{
    for (int i = 0; i < 100; ++i) {
        a->enemy1[i].frame.width = 100;
        a->enemy1[i].frame.height = 100;
        a->enemy1[i].frame.top = 0;
        a->enemy1[i].frame.left = 0;
        a->enemy1[i].xy.y = 0;
        a->enemy1[i].xy.x = 140;
        a->enemy1[i].angle = 0;
        a->enemy1[i].route = 0;
        a->enemy1[i].hp = 3;
        a->enemy1[i].i = 0;
        a->enemy1[i].alive = true;
        a->enemy1[i].hitted = false;
        v2init_enemy(a, i);
    }
}

void v2init_enemy2(all *a, int i)
{
    a->enemy2[i].texture = sfTexture_createFromFile("texture/Enemy2.png",NULL);
}

void v3init_enemy(all *a, int i)
{
    a->enemy2[i].hitted = false;
    a->enemy2[i].alive = true;
    a->enemy2[i].y = 0;
    a->enemy2[i].x = 0;
    a->enemy2[i].decal = 1;
    a->enemy2[i].speed = 1;
    a->enemy2[i].clock = sfClock_create();
    v2init_enemy2(a, i);
    a->enemy2[i].sprite = sfSprite_create();
    sfSprite_setTexture(a->enemy2[i].sprite, a->enemy2[i].texture, sfTrue);
}

void init_enemy2(all *a)
{
    for (int i = 0; i < 100; ++i) {
        a->enemy2[i].frame.width = 100;
        a->enemy2[i].frame.height = 100;
        a->enemy2[i].frame.top = 0;
        a->enemy2[i].frame.left = 0;
        a->enemy2[i].xy.y = 0;
        a->enemy2[i].xy.x = 140;
        a->enemy2[i].angle = 0;
        a->enemy2[i].route = 0;
        a->enemy2[i].hp = 10;
        a->enemy2[i].i = 0;
        v3init_enemy(a, i);
    }
}

void init_button(button_t *button,
                sfVector2f position,
                sfVector2f size,
                char *type)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    button->texture = sfTexture_createFromFile(type, NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
}