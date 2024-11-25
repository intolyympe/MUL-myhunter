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
    sfSprite* sprite1;
    sfSprite* sprite2;
} game_t;
//game_t* game = malloc(sizeof(game_t))

typedef struct duck_s {
    sfSprite *sprite1;
    sfTexture *texture1;
    sfVector2f position;
    sfVector2f vector;
    sfIntRect rect;
} duck_t;

duck_t *init_duck1(void);
sfSprite *create_sprite2(char *filepath);
int events(game_t *test);
int init_window(game_t *test);
int clean_window(game_t* test, duck_t *duck);
void animate_duck(duck_t *duck, sfClock *clock);
void move_duck(duck_t *duck);

#endif