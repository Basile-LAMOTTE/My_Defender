/*
** EPITECH PROJECT, 2021
** loose event
** File description:
** check the loose event
*/

#include <../include/my.h>

int rande(int max, int min)
{
    srand(time(NULL));
    int nb = (rand()%max)+min;
    return nb;
}

int checkloose(all *a) {
    for (int i = 0; i < a->nb_enemy1; ++i) {
        if (a->enemy1[i].xy.x > WIDTH/1.25+100 && a->enemy1[i].hp > 0) {
            a->enemy1[i].hp = 0;
            a->glohp -= 1;
        }
        if (a->glohp <= 0)
            return 1;
    }
    for (int i = 0; i < a->nb_enemy2; ++i) {
        if (a->enemy2[i].xy.x > WIDTH/1.25+100 && a->enemy2[i].hp > 0) {
            a->enemy2[i].hp = 0;
            a->glohp -= 1;
        }
        if (a->glohp <= 0)
            return 1;
    }
    return 0;
}

void v2displayHp(all a, char *array, sfVector2f position)
{
    sfText_setString(a.text, array);
    sfText_setColor(a.text, sfBlack);
    sfText_setFont(a.text, a.font);
    sfText_setCharacterSize(a.text, 100);
    sfText_setPosition(a.text, position);
    sfRenderWindow_drawText(a.window, a.text, NULL);
}

void displayHp(all a)
{
    sfVector2f position;
    position.x = WIDTH/1.25 + 68 ;
    position.y = HEIGHT/1.5 + 107 ;
    char *array = intostring(a.glohp);

    a.font = sfFont_createFromFile("texture/arial.ttf");
    a.text = sfText_create();
    v2displayHp(a, array, position);
}