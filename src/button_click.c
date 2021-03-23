/*
** EPITECH PROJECT, 2021
** buttonclick
** File description:
** buttonclick
*/

#include <../include/my.h>

int button_is_clicked(  button_t button,
                        sfVector2f click_position,
                        sfVector2f size)
{
    int x = click_position.x;
    int y = click_position.y;
    sfVector2f position = sfRectangleShape_getPosition(button.rect);
    if (x >= position.x && x <= position.x + size.x)
        if (y >= position.y && y <= position.y + size.y)
            return 1;
    return 0;
}

void buttonClick_basicScene(all a, sfVector2f click_position, int *scene)
{
    if (button_is_clicked(a.buttonPlay, click_position, a.size) == 1) {
        sfMusic_stop(a.click);
        sfMusic_play(a.click);
        *scene += 1;
    }
    if (button_is_clicked(a.buttonQuit, click_position, a.size) == 1) {
        sfMusic_stop(a.click);
        sfMusic_play(a.click);
        sfRenderWindow_close(a.window);
    }
}

void buttonClick_secondScene(all a, sfVector2f click_position, int *scene)
{
    if (button_is_clicked(a.buttonInterface, click_position, a.size2) == 1) {
        sfMusic_stop(a.bell);
        sfMusic_play(a.bell);
        *scene += 1;
    }
}

void v4buttonClick_interface(all *a, sfVector2f click_position, int *scene)
{
    if (button_is_clicked(a->button4, click_position, a->size2) == 1) {
        if (a->gold >= 200) {
            sfMusic_stop(a->click);
            sfMusic_play(a->click);
            a->placing = 4;
            a->gold -= 200;
        }
        else {
            sfMusic_stop(a->error);
            sfMusic_play(a->error);
        }
    }
    if (a->placing != 0)
        *scene -= 1;
}

all buttonClick_interface(all* a, sfVector2f click_position, int *scene)
{
    if (button_is_clicked(a->button1, click_position, a->size2) == 1) {
        if (a->gold >= 100) {
            sfMusic_stop(a->click);
            sfMusic_play(a->click);
            a->placing = 1;
            a->gold -= 100;
        }
        else {
            sfMusic_stop(a->error);
            sfMusic_play(a->error);
        }
    }
    v2buttonClick_interface(a, click_position);
    v4buttonClick_interface(a , click_position , scene);
    return *a;
}