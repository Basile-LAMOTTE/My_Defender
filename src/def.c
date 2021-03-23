/*
** EPITECH PROJECT, 2021
** define
** File description:
** define
*/

#include <../include/my.h>

void def_btn2(all *a) {
    a->positionBtn1.x = WIDTH - 400;
    a->positionBtn1.y = HEIGHT/3 - 175;
    a->positionBtn2.x = WIDTH - 400;
    a->positionBtn2.y = HEIGHT/3;
    a->positionBtn3.x = WIDTH - 400;
    a->positionBtn3.y = HEIGHT/3 + 175;
    a->positionBtn4.x = WIDTH - 400;
    a->positionBtn4.y = HEIGHT/3 + 350;
    a->size2.x = 100;
    a->size2.y = 100;
    init_button(&a->buttonPlay, a->positionPlay, a->size, "texture/play.png");
    init_button(&a->buttonQuit, a->positionQuit, a->size, "texture/quit.png");
    init_button(&a->buttonInterface,
                a->positionBtnInterface, a->size2, "texture/shop.png");
    init_button(&a->button1, a->positionBtn1, a->size2, "texture/Icon1.jpg");
    init_button(&a->button2, a->positionBtn2, a->size2, "texture/Icon2.jpg");
    init_button(&a->button3, a->positionBtn3, a->size2, "texture/Icon3.jpg");
    init_button(&a->button4, a->positionBtn4, a->size2, "texture/Icon4.jpg");
}

void def_btn(all *a)
{
    a->positionPlay.x = WIDTH/2 - 350;
    a->positionPlay.y = HEIGHT/2 - 50;
    a->size.x = 250;
    a->size.y = 50;
    a->positionQuit.x = WIDTH/2 - 50;
    a->positionQuit.y = HEIGHT/2 - 50;
    a->positionBtnInterface.x = WIDTH/1.1;
    a->positionBtnInterface.y = HEIGHT/16;
    a->shoot[0] = sfMusic_createFromFile("sounds/boom1.ogg");
    a->shoot[1] = sfMusic_createFromFile("sounds/boom2.ogg");
    a->shoot[2] = sfMusic_createFromFile("sounds/boom3.ogg");
    a->shoot[3] = sfMusic_createFromFile("sounds/boom4.ogg");
    a->shoot[4] = sfMusic_createFromFile("sounds/boom5.ogg");
    a->explosion[0] = sfMusic_createFromFile("sounds/Explosion1.ogg");
    a->explosion[1] = sfMusic_createFromFile("sounds/Explosion2.ogg");
    a->explosion[2] = sfMusic_createFromFile("sounds/Explosion3.ogg");
    for (int i = 0; i < 3; ++i)
        sfMusic_setVolume(a->explosion[i], 50);
    def_btn2(a);
}

void def2(all *a)
{
    a->spawn = rande(10, 1);
    a->nb_enemy1 = 0;
    a->nb_enemy2 = 0;
    a->gold = 200;
    a->nb_wave = 1;
    a->waveEnded = true;
    a->click = sfMusic_createFromFile("sounds/click.wav");
    a->click2 = sfMusic_createFromFile("sounds/click2.wav");
    a->error = sfMusic_createFromFile("sounds/error.wav");
    a->bell = sfMusic_createFromFile("sounds/bell.wav");
    init_enemy1(a);
    init_enemy2(a);
    init_turret1(a);
    init_turret2(a);
    init_turret3(a);
    init_turret4(a);
}

void def(all *a)
{
    a->window = create_window();
    def_btn(a);
    a->background = init_background("texture/MainMenu.jpg");
    a->background2 = init_background("texture/Map.jpg");
    a->background3 = init_background("texture/MapInterface.jpg");
    a->looseScreen = init_background("texture/endscene.jpg");
    a->i1 = 0;
    a->i2 = 0;
    a->i3 = 0;
    a->i4 = 0;
    a->glohp = 5;
    a->placing = 0;
    a->clock = sfClock_create();
    a->towerclock = sfClock_create();
    a->goldclock = sfClock_create();
    def2(a);
}
