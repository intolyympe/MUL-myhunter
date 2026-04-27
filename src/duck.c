/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** duck.c
*/

#include "../include/hunter.h"
#include "../include/my.h"

duck_t *init_duck(void)
{
    duck_t *duck = malloc(sizeof(duck_t));

    duck->sprite_duck = sfSprite_create();
    duck->texture_duck = sfTexture_createFromFile("img/duck.png", NULL);
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    sfSprite_setTexture(duck->sprite_duck, duck->texture_duck, sfTrue);
    sfSprite_setTextureRect(duck->sprite_duck, duck->rect);
    sfSprite_setPosition(duck->sprite_duck, (sfVector2f){-200, 50});
    duck->move_clock = sfClock_create();
    return duck;
}

void animate_duck(duck_t *duck, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.16f) {
        duck->rect.left += 110;
        if (duck->rect.left >= 330) {
            duck->rect.left = 0;
        }
        sfSprite_setTextureRect(duck->sprite_duck, duck->rect);
        sfClock_restart(clock);
    }
}

int move_duck(duck_t *duck)
{
    float delta = sfTime_asSeconds(sfClock_getElapsedTime(duck->move_clock));

    sfClock_restart(duck->move_clock);
    duck->position = sfSprite_getPosition(duck->sprite_duck);
    sfSprite_move(duck->sprite_duck, (sfVector2f){600.0f * delta, 0});
    if (duck->position.x < 2000)
        return 0;
    sfSprite_setPosition(duck->sprite_duck, (sfVector2f){-200, rand() % 650});
    return 1;
}

void clean_duck(duck_t *duck)
{
    sfClock_destroy(duck->move_clock);
    sfSprite_destroy(duck->sprite_duck);
    free(duck);
}

int duck_is_shot(sfRenderWindow *window, duck_t *duck)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(duck->sprite_duck);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (!sfFloatRect_contains(&rect, mouse.x, mouse.y))
        return 0;
    sfSprite_setPosition(duck->sprite_duck, (sfVector2f){-200, rand() % 650});
    return 1;
}
