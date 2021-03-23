/*
** EPITECH PROJECT, 2021
** main
** File description:
** main for my defender project
*/

#include <../include/my.h>

void scene0(all *a, int *scene)
{
    *a = basic_event_window(*a, scene);
    sfRenderWindow_drawSprite(a->window, a->background.sprite, NULL);
    sfRenderWindow_drawRectangleShape(  a->window,
                                        a->buttonPlay.rect, NULL);
    sfRenderWindow_drawRectangleShape   (a->window,
                                        a->buttonQuit.rect, NULL);
}

void v2scene1(all *a, int *scene)
{
    for (int i = 0; i < a->i2; ++i) {
        if (a->turret2[i].hp > 0)
            sfRenderWindow_drawSprite(a->window, a->turret2[i].sprite, NULL);
    }
    for (int i = 0; i < a->i3; ++i)
        sfRenderWindow_drawSprite(a->window, a->turret3[i].sprite, NULL);
    for (int i = 0; i < a->i4; ++i)
        sfRenderWindow_drawSprite(a->window, a->turret4[i].sprite, NULL);
    sfRenderWindow_drawRectangleShape(a->window,
                                      a->buttonInterface.rect, NULL);
    if (checkloose(a) == 1)
        *scene = 3;
    displayHp(*a);
}

void scene1(all *a, int *scene)
{
    *a = basic_event_window(*a, scene);
    sfRenderWindow_drawSprite(a->window, a->background2.sprite, NULL);
    spawnenemi(a);
    update_enemy1(a);
    update_enemy2(a);
    root(a);
    r22t(a);
    touchenemy(a);
    for (int i = 0; i < a->nb_enemy1 ;++i) {
        if (a->enemy1[i].hp > 0)
            sfRenderWindow_drawSprite(a->window, a->enemy1[i].sprite, NULL);
    }
    for (int i = 0; i < a->nb_enemy2 ;++i) {
        if (a->enemy2[i].hp > 0)
            sfRenderWindow_drawSprite(a->window, a->enemy2[i].sprite, NULL);
    }
    for (int i = 0; i < a->i1; ++i)
        sfRenderWindow_drawSprite(a->window, a->turret1[i].sprite, NULL);
    v2scene1(a, scene);
}

void scene2(all *a, int *scene)
{
    *a = basic_event_window(*a, scene);
    sfRenderWindow_drawSprite(a->window, a->background3.sprite, NULL);
    sfRenderWindow_drawRectangleShape(a->window, a->button1.rect, NULL);
    sfRenderWindow_drawRectangleShape(a->window, a->button2.rect, NULL);
    sfRenderWindow_drawRectangleShape(a->window, a->button3.rect, NULL);
    sfRenderWindow_drawRectangleShape(a->window, a->button4.rect, NULL);
}

void omain(all *a)
{
    for (int i = 0; i < 5; ++i)
        sfMusic_destroy(a->shoot[i]);
    for (int i = 0; i < 3; ++i)
        sfMusic_destroy(a->explosion[i]);
    sfMusic_destroy(a->click);
    sfMusic_destroy(a->error);
    sfMusic_destroy(a->click2);
    sfMusic_destroy(a->bell);
    sfRenderWindow_destroy(a->window);
}