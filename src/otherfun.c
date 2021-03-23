/*
** EPITECH PROJECT, 2021
** other init
** File description:
** other int
*/

#include <../include/my.h>

sfRenderWindow *create_window(void)
{
    sfRenderWindow *new_window;
    sfVideoMode video_mode;

    video_mode.bitsPerPixel = 32;
    video_mode.width = WIDTH;
    video_mode.height = HEIGHT;
    new_window = sfRenderWindow_create(video_mode, "my_defender",
                                       sfClose, NULL);
    if (new_window == NULL)
        return (NULL);
    sfRenderWindow_setPosition(new_window, (sfVector2i){70, 0});
    sfRenderWindow_setFramerateLimit(new_window, 60);
    return (new_window);
}

void e2defpos(pos *p, all *a, int i, int y)
{
    p->pos1x = a->turret1[i].position.x;
    p->postx = a->enemy2[y].xy.x - 50;
    p->pos1y = a->turret1[i].position.y;
    p->posty = a->enemy2[y].xy.y - 50;
}

void v3buttonClick_interface(all *a, sfVector2f click_position)
{
    if (button_is_clicked(a->button3, click_position, a->size2) == 1) {
        if (a->gold >= 300) {
            sfMusic_stop(a->click);
            sfMusic_play(a->click);
            a->placing = 3;
            a->gold -= 300;
        }
        else {
            sfMusic_stop(a->error);
            sfMusic_play(a->error);
        }
    }
}

void v2buttonClick_interface(all *a, sfVector2f click_position)
{
    if (button_is_clicked(a->button2, click_position, a->size2) == 1) {
            if (a->gold >= 50) {
                sfMusic_stop(a->click);
                sfMusic_play(a->click);
                a->placing = 2;
                a->gold -= 50;
            }
            else {
                sfMusic_stop(a->error);
                sfMusic_play(a->error);
            }
        }
    v3buttonClick_interface(a, click_position);
}

void v2rangetowert4(all *a, int i)
{
    int pos1x;
    int postx;
    int pos1y;
    int posty;
    for (int y = 0; y < a->nb_enemy1; ++y) {
        pos1x = a->turret4[i].position.x + 150;
        postx = a->enemy1[y].xy.x - 50;
        pos1y = a->turret4[i].position.y + 150;
        posty = a->enemy1[y].xy.y - 50;
        if (postx <  pos1x && postx >  pos1x - 400) {
            if (posty < pos1y && posty >  pos1y - 400) {
                if (a->enemy1[y].hp > 0) {
                    a->enemy1[y].speed = 1;
                }
            }
        }
        else
            a->enemy1[y].speed = 2;
    }
    e2v2rangetowert4(a, i);
}