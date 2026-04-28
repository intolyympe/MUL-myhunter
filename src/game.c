/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** game.c
*/

#include "../include/hunter.h"
#include "../include/my.h"

void start_game(game_t *game, player_t *player)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->s_start);

    player->mouse_position = sfMouse_getPositionRenderWindow(game->window);
    if (sfFloatRect_contains(&rect,
        player->mouse_position.x, player->mouse_position.y)) {
        game->state = GAME;
    }
}

void clean_all(game_t *game, duck_t *duk, player_t *player)
{
    clean_duck(duk);
    clean_player(player);
    clean_window(game);
}

void run_game(game_t *game, duck_t *duk, player_t *player, sfClock *clock)
{
    while (sfRenderWindow_isOpen(game->window)) {
        events(game, duk, player);
        game_p(game, duk, player, clock);
    }
}

static void update_state(game_t *game, player_t *player)
{
    if (game->state == GAME && player->life == 0)
        game->state = GAMEOVER;
}

static void draw_state(game_t *game, duck_t *duk, player_t *player,
    sfClock *clock)
{
    if (game->state == MENU) {
        sfRenderWindow_drawSprite(game->window, game->sprite_bg, NULL);
        sfRenderWindow_drawSprite(game->window, game->s_start, NULL);
    }
    if (game->state == GAMEOVER) {
        sfRenderWindow_drawSprite(game->window, game->sprite_go, NULL);
        sfRenderWindow_drawText(game->window, player->btn_replay, NULL);
    }
    if (game->state == GAME) {
        draw_sprite(game, duk, player);
        animate_duck(duk, clock);
        if (move_duck(duk))
            player_on_escape(player);
    }
}

void game_p(game_t *game, duck_t *duk, player_t *player, sfClock *clock)
{
    sfRenderWindow_clear(game->window, sfBlack);
    update_state(game, player);
    draw_state(game, duk, player, clock);
    sfRenderWindow_display(game->window);
}
