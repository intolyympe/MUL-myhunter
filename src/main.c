/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** main.c
*/

#include "../include/hunter.h"
#include "../include/my.h"
#include <time.h>

int info_help(int ac, char **av)
{
    if (ac == 1 || (my_strcmp(av[1], "-h") != 0 &&
        my_strcmp(av[1], "--help") != 0))
        return 0;
    my_printf("%s\n\t%s\n\n", "USAGE", "./my_hunter");
    my_printf("%s\n", "DESCRIPTION");
    my_printf("\t%s\n", "The basic rules for my_hunter are as follows:");
    my_printf("\t%s\n", "• the player is a hunter who shoots ducks.");
    my_printf("\t%s\n", "• ducks move from one side to another.");
    my_printf("\t%s\n", "• the player can click on them to shoot them.");
    return 1;
}

int main(int ac, char **av)
{
    game_t *game = init_window();
    player_t *player = init_player();
    duck_t *duk = init_duck();
    sfClock *clock = sfClock_create();

    srand(time(NULL));
    if (info_help(ac, av))
        return 0;
    if (!game || !game->window || !player || !duk) {
        write(2, "Error: initialization failed\n", 29);
        return 84;
    }
    game->state = MENU;
    run_game(game, duk, player, clock);
    clean_all(game, duk, player);
    return 0;
}
