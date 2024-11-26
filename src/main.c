/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** main.c
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
#include <string.h>
#include "../include/hunter.h"
#include "../include/my.h"

int info_help(int ac, char **av)
{
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0 ||
        my_strcmp(av[1], "--help") == 0) {
            my_printf("USAGE\n\t./my_hunter \n\n");
            my_printf("DESCRIPTION\n\t ");
            return 1;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    game_t test;
    player_t player;
    duck_t *duk = init_duck1();
    sfClock *clock = sfClock_create();

    if (info_help(ac, av))
        return 0;
    init_window(&test);
    while (sfRenderWindow_isOpen(test.window)) {
        events(&test, duk, &player);
        sfRenderWindow_clear(test.window, sfBlack);
        sfRenderWindow_drawSprite(test.window, test.sprite2, NULL);
        sfRenderWindow_drawSprite(test.window, duk->sprite1, NULL);
        animate_duck(duk, clock);
        move_duck(duk);
        sfRenderWindow_display(test.window);
    }
    clean_window(&test, duk);
    return 0;
}