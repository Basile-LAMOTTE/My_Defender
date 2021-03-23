/*
** EPITECH PROJECT, 2021
** main
** File description:
** main for my defender project
*/

#include <../include/my.h>

void aplacing2(all *a, sfVector2f *turret_position)
{
    if (a->placing == 3) {
        sfMusic_stop(a->click2);
        sfMusic_play(a->click2);
        a->turret3[a->i3].position = *turret_position;
        sfSprite_setPosition(a->turret3[a->i3].sprite,
                             a->turret3[a->i3].position);
        a->i3++;
    }
    if (a->placing == 4) {
        sfMusic_stop(a->click2);
        sfMusic_play(a->click2);
        a->turret4[a->i4].position = *turret_position;
        sfSprite_setPosition(a->turret4[a->i4].sprite,
                             a->turret4[a->i4].position);
        a->i4++;
    }
    a->placing = 0;
}

void aplacing(all *a, sfVector2f *turret_position)
{
    if (a->placing == 1) {
        sfMusic_stop(a->click2);
        sfMusic_play(a->click2);
        a->turret1[a->i1].position = *turret_position;
        sfSprite_setPosition(a->turret1[a->i1].sprite,
                             a->turret1[a->i1].position);
        a->i1++;
    }
    if (a->placing == 2) {
        sfMusic_stop(a->click2);
        sfMusic_play(a->click2);
        a->turret2[a->i2].position = *turret_position;
        sfSprite_setPosition(a->turret2[a->i2].sprite,
                             a->turret2[a->i2].position);
        a->i2++;
    }
    aplacing2(a, turret_position);
}

void eventmouse(all *a, sfEvent event, int *scene)
{
    sfVector2f click_position;
    sfVector2f turret_position;
    click_position.x = event.mouseButton.x;
    click_position.y = event.mouseButton.y;
    turret_position.x = click_position.x - 50;
    turret_position.y = click_position.y - 50;
    if (a->placing != 0)
        aplacing(a, &turret_position);
    if (*scene == 2)
        *a = buttonClick_interface(a, click_position, scene);
    if (*scene == 1)
        buttonClick_secondScene(*a, click_position, scene);
    if (*scene == 0)
        buttonClick_basicScene(*a, click_position, scene);
}

all basic_event_window(all a, int *scene)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(a.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(a.window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            if (*scene == 0 || *scene == 3)
                sfRenderWindow_close(a.window);
            else
                *scene -= 1;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.button == sfMouseLeft)
                eventmouse(&a, event, scene);
        }
    }
    return a;
}

int main(void)
{
    int scene = 0;
    all a;
    def(&a);
    if (a.window == NULL)
        return (84);
    while (sfRenderWindow_isOpen(a.window)) {
        if (scene == 0)
            scene0(&a, &scene);
        if (scene == 1)
            scene1(&a, &scene);
        if (scene == 2)
            scene2(&a, &scene);
        if (scene == 3) {
            basic_event_window(a, &scene);
            sfRenderWindow_drawSprite(a.window, a.looseScreen.sprite, NULL);
        }
        sfRenderWindow_display(a.window);
    }
    omain(&a);
    return (0);
}