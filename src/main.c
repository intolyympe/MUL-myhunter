/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** main.c
*/

#include "../include/hunter.h"
#include "../include/my.h"

int info_help(int ac, char **av)
{
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0 ||
        my_strcmp(av[1], "--help") == 0) {
                my_printf("%s\n\t%s\n\n", "USAGE", "./my_hunter");
                my_printf("%s\n", "DESCRIPTION");
                my_printf("\t%s", "The basic rules for the my_hunter");
                my_printf("%s\n\t%s", "as follows:", "• the player");
                my_printf("\t%s\n", "is a hunter who shoots ducks.");
                my_printf("\t%s", "• ducks must appear on the screen and ");
                my_printf("%s\n", "move from one side to another.");
                my_printf("\t%s", "• the player can click on");
                my_printf("%s\n\n", "them to shoot them.");
            return 1;
        }
    }
    return 0;
}

void start_game(game_t *game, player_t *player)
{
    sfFloatRect rect3 = sfSprite_getGlobalBounds(game->s_start);

    player->mouse_position = sfMouse_getPositionRenderWindow(game->window);
    if (sfFloatRect_contains(&rect3,
    player->mouse_position.x, player->mouse_position.y)) {
        game->state = GAME;
    }
}

void game_p(game_t *game, duck_t *duk, player_t *player, sfClock *clock)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->state == MENU) {
        sfRenderWindow_drawSprite(game->window, game->sprite_bg, NULL);
        sfRenderWindow_drawSprite(game->window, game->s_start, NULL);
    }
    if (game->state == GAME) {
        if (player->life > 0) {
            draw_sprite(game, duk, player);
            animate_duck(duk, clock);
            move_duck(duk, player);
        } else
            sfRenderWindow_drawSprite(game->window, game->sprite_go, NULL);
    }
    sfRenderWindow_display(game->window);
}

int main(int ac, char **av)
{
    game_t *game = init_window();
    player_t *player = init_player();
    duck_t *duk = init_duck();
    sfClock *clock = sfClock_create();

    if (info_help(ac, av))
        return 0;
    if (!game || !game->window || !player || !duk) {
        write(2, "Error: initialization failed\n", 29);
        return 84;
    }
    game->state = MENU;
    while (sfRenderWindow_isOpen(game->window)) {
            events(game, duk, player);
            game_p(game, duk, player, clock);
    }
    clean_window(game, duk, player);
    return 0;
}
