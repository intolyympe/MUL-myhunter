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

void move_duck(duck_t *duck, player_t *player)
{
    float delta = sfTime_asSeconds(sfClock_getElapsedTime(duck->move_clock));

    sfClock_restart(duck->move_clock);
    duck->position = sfSprite_getPosition(duck->sprite_duck);
    sfSprite_move(duck->sprite_duck, (sfVector2f){600.0f * delta, 0});
    if (duck->position.x >= 2000) {
        player->rect_life.top -= 78;
        player->life -= 1;
        sfSprite_setTextureRect(player->sprite_life, player->rect_life);
        sfSprite_setPosition(duck->sprite_duck,
            (sfVector2f){-200, rand() % 650});
    }
}

void clean_duck(duck_t *duck)
{
    sfClock_destroy(duck->move_clock);
    sfSprite_destroy(duck->sprite_duck);
    free(duck);
}

void kill_duck(sfRenderWindow *window, duck_t *duck, player_t *player)
{
    sfFloatRect rect2 = sfSprite_getGlobalBounds(duck->sprite_duck);

    player->mouse_position = sfMouse_getPositionRenderWindow(window);
    if (sfFloatRect_contains(&rect2,
                        player->mouse_position.x, player->mouse_position.y)) {
            player->score += 100;
            sfText_setString(player->text, my_int_to_str(player->score));
            sfSprite_setPosition(duck->sprite_duck,
            (sfVector2f){-200, rand() % 650});
    }
}
