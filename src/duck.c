/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** duck.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Types.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/hunter.h"
#include "../include/my.h"

duck_t *init_duck1(void)
{
    duck_t *duck = malloc(sizeof(duck_t));

    duck->sprite1 = sfSprite_create();
    duck->texture1 = sfTexture_createFromFile("img/duck.png", NULL);
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    sfSprite_setTexture(duck->sprite1, duck->texture1, sfTrue);
    sfSprite_setTextureRect(duck->sprite1, duck->rect);
    return duck;
}

void animate_duck(duck_t *duck, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.16f) {
        duck->rect.left += 110;
        if (duck->rect.left >= 330) {
        duck->rect.left = 0;
        }
        sfSprite_setTextureRect(duck->sprite1, duck->rect);
        sfClock_restart(clock);
    }
}

void move_duck(duck_t *duck)
{
    sfVector2f value = (sfVector2f){-200, rand() % 300};

    duck->position = sfSprite_getPosition(duck->sprite1);
    sfSprite_move(duck->sprite1, (sfVector2f){2, 0});
    if (duck->position.x >= 740)
        sfSprite_setPosition(duck->sprite1, value);
}