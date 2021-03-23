/*
** EPITECH PROJECT, 2021
** intiturret
** File description:
** init the turrets
*/

#include <../include/my.h>

sfVector2f vecpos(void)
{
    sfVector2f position;
    position.x = 50;
    position.y = 50;
    return position;
}

void maingoldv2(all *a, char *array, sfVector2f position)
{
    sfText_setString(a->goldtext, array);
    sfText_setColor(a->goldtext, sfBlack);
    sfText_setFont(a->goldtext, a->goldfont);
    sfText_setCharacterSize(a->goldtext, 100);
    sfText_setPosition(a->goldtext, position);
    sfRenderWindow_drawText(a->window, a->goldtext, NULL);
}

void maingold(all *a)
{
    char *array = intostring(a->gold);
    a->goldfont = sfFont_createFromFile("texture/arial.ttf");
    a->goldtext = sfText_create();
    for (int y = 0; y < a->nb_enemy1; ++y) {
        if (a->enemy1[y].alive == true && a->enemy1[y].hp <= 0) {
            a->gold += 25;
            a->enemy1[y].alive = false;
        }
    }
    for (int y = 0; y < a->nb_enemy2; ++y) {
        if (a->enemy2[y].alive == true && a->enemy2[y].hp <= 0) {
            a->gold += 25;
            a->enemy2[y].alive = false;
        }
    }
    maingoldv2(a, array, vecpos());
}
