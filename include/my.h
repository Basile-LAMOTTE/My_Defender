/*
** EPITECH PROJECT, 2020
** Code_Button_CSFML
** File description:
** defender
*/

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define WIDTH 1850
#define HEIGHT 1015

typedef struct button_s button_t;
typedef struct turrets_s turrets_t;

struct button_s {
    sfRectangleShape *rect;
    sfIntRect frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *clock;
    sfTime time;
    int hp;
};

typedef struct enemy_t enemy_t;
struct enemy_t
{
    sfSprite *sprite;
    sfClock *clock;
    sfTexture *texture;
    sfIntRect frame;
    sfTime time;
    sfVector2f xy;
    bool alive;
    bool hitted;
    float angle;
    int speed;
    int decal;
    int hp;
    int i;
    int x;
    int y;
    int route;
};

typedef struct all all;
struct all
{
    sfMusic *shoot[5];
    sfMusic *explosion[3];
    sfMusic *click;
    sfMusic *bell;
    sfMusic *click2;
    sfMusic *error;
    sfClock *towerclock;
    sfTime towertime;
    sfClock *goldclock;
    sfTime goldtime;
    sfText *goldtext;
    sfFont *goldfont;
    sfRenderWindow *window;
    sfVector2f positionPlay;
    sfVector2f positionQuit;
    sfVector2f positionBtnInterface;
    sfVector2f positionBtn1;
    sfVector2f positionBtn2;
    sfVector2f positionBtn3;
    sfVector2f positionBtn4;
    sfVector2f size;
    sfVector2f size2;
    button_t turret1[10];
    button_t turret2[10];
    button_t turret3[10];
    button_t turret4[10];
    enemy_t enemy1[100];
    enemy_t enemy2[100];
    sfText *text;
    sfFont *font;
    button_t background;
    button_t background2;
    button_t background3;
    button_t looseScreen;
    button_t buttonPlay;
    button_t buttonQuit;
    button_t buttonInterface;
    button_t button1;
    button_t button2;
    button_t button3;
    button_t button4;
    sfClock *clock;
    sfTime time;
    bool waveEnded;
    int gold;
    int nb_wave;
    int glohp;
    int placing; //placing = 0 -> not placing
    int i1;
    int i2;
    int i3;
    int i4;
    int spawn;
    int nb_enemy1;
    int nb_enemy2;
};

typedef struct pos pos;
struct pos
{
    int pos1x;
    int postx;
    int pos1y;
    int posty;
};

void def(all *a);
void root(all *a);
void r22t(all *a);

/* Tower range */
void touchenemy(all *a);
void v2rangetowert1(all *a, int i);
void v3rangetowert2(all *a, int y, int i);
void v2rangetowert2(all *a, int i);
void v2rangetowert3(all *a, int i);
void v2rangetowert4(all *a, int i);
void e2defpos(pos *p, all *a, int i, int y);
void e2v2rangetowert1(all *a, int i);
void e2v3rangetowert2(all *a, int y , int i);
void e2v2rangetowert2(all *a, int i);
void e2v2rangetowert3(all *a, int i);
void e2v2rangetowert4(all *a, int i);

/* Loose event */
int rande(int max, int min);
int checkloose(all *a);
void displayHp(all a);

/* init turret */
void init_turret1(all *a);
void init_turret2(all *a);
void init_turret3(all *a);
void init_turret4(all *a);

/* init other */
sfRenderWindow *create_window(void);
button_t init_background(char *file);
void init_enemy1(all *a);
void init_enemy2(all *a);
void init_button(button_t *button, sfVector2f position, sfVector2f size, char *type);
void init_buttonface(all *a, char *type);

/* Manage enemy */
void spawnenemi(all *a);
void update_enemy1(all *a);
void update_enemy2(all *a);
void rotatey1(all *a);
void rotatey2(all *a);
void rotate_enemy1(all *a);
void rotate_enemy2(all *a);

/* Buton click */
int button_is_clicked(button_t, sfVector2f, sfVector2f);
void buttonClick_basicScene(all, sfVector2f, int *);
void buttonClick_secondScene(all, sfVector2f, int *);
all buttonClick_interface(all*, sfVector2f, int *);

/* Lib */
char *intostring(int oct);
char *my_revstr(char *str);
int my_strlen(char *str);

void maingold(all *a);

sfRenderWindow *create_window();

void scene0(all *a, int *scene);
void v2scene1(all *a, int *scene);
void scene1(all *a, int *scene);
void scene2(all *a, int *scene);
void omain(all *a);
all basic_event_window(all a, int *scene);

void v3buttonClick_interface(all *a, sfVector2f click_position);

void v2buttonClick_interface(all *a, sfVector2f click_position);

button_t init_background(char *file);

void v2init_enemy1(all *a, int i);

void v2init_enemy(all *a, int i);

void v2rangetowert4(all *a, int i);

void update_frame(all *a, int i);