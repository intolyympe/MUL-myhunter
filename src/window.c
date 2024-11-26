/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** window.c
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

int init_window(game_t *game)
{
    sfVideoMode mode = {736, 552, 32};

    if (!game->window)
        return 84;
    game->window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    game->sprite2 = create_background("img/background1.jpeg");
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return 0;
}

int events(game_t *game, duck_t *duk, player_t *player)
{
    sfEvent event;

        while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            kill_duck(game->window, duk, player);
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
    return 0;
}

int clean_window(game_t *game, duck_t *duck)
{
    sfSprite_destroy(duck->sprite1);
    sfSprite_destroy(game->sprite2);
    sfRenderWindow_destroy(game->window);
    return 0;
}