/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** hunter.h
*/
#ifndef HUNTER_H
    #define HUNTER_H

    #include <SFML/Graphics.h>
    #include <SFML/Config.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Window.h>
    #include <SFML/Graphics/Rect.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "../include/hunter.h"
    #include "../include/my.h"

typedef struct game_s {
    sfRenderWindow* window;
    sfVideoMode mode;
    sfSprite* sprite1;
    sfSprite* sprite2;
    sfSprite* sprite3;
} game_t;
//

typedef struct duck_s {
    sfSprite *sprite1;
    sfTexture *texture1;
    sfVector2f position;
    sfVector2f rand_value;
    sfVector2f vector;
    sfIntRect rect;
    sfVector2f scale;
    int is_dead;
} duck_t;

typedef struct player_s {
    int score;
    sfVector2i mouse_position;
} player_t;

duck_t *init_duck1(void);
sfSprite *create_background(char *filepath);
int events(game_t *test, duck_t *duk, player_t *player);
int init_window(game_t *test);
int clean_window(game_t *test, duck_t *duck);
void animate_duck(duck_t *duck, sfClock *clock);
void move_duck(duck_t *duck);
void kill_duck(sfRenderWindow *window, duck_t *duck, player_t *player);

#endif