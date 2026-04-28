/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** window.c
*/

#include "../include/hunter.h"
#include "../include/my.h"

game_t *init_window(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->mode.width = 1920;
    game->mode.height = 1080;
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode, "SFML window",
    sfResize | sfClose, NULL);
    game->sprite_bg = sfSprite_create();
    game->texture_bg = sfTexture_createFromFile("img/background1.jpg", NULL);
    sfSprite_setTexture(game->sprite_bg, game->texture_bg, sfTrue);
    game->s_start = sfSprite_create();
    game->t_start = sfTexture_createFromFile("img/start-button.png", NULL);
    sfSprite_setScale(game->s_start, (sfVector2f){15, 15});
    sfSprite_setTexture(game->s_start, game->t_start, sfTrue);
    sfSprite_setPosition(game->s_start, (sfVector2f){750, 400});
    game->sprite_go = sfSprite_create();
    game->texture_go = sfTexture_createFromFile("img/game-over.jpg", NULL);
    sfSprite_setTexture(game->sprite_go, game->texture_go, sfTrue);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return game;
}

int draw_sprite(game_t *game, duck_t *duk, player_t *player)
{
    sfRenderWindow_drawSprite(game->window, game->sprite_bg, NULL);
    sfRenderWindow_drawSprite(game->window, player->sprite_life, NULL);
    sfRenderWindow_drawSprite(game->window, duk->sprite_duck, NULL);
    sfRenderWindow_drawText(game->window, player->text, NULL);
    return 0;
}

static void handle_replay(game_t *game, duck_t *duk, player_t *player)
{
    sfFloatRect rect = sfText_getGlobalBounds(player->btn_replay);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (!sfFloatRect_contains(&rect, mouse.x, mouse.y))
        return;
    player_reset(player);
    sfSprite_setPosition(duk->sprite_duck, (sfVector2f){-200, 50});
    game->state = GAME;
}

int events(game_t *game, duck_t *duk, player_t *player)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed &&
            sfMouse_isButtonPressed(sfMouseLeft)) {
            if (game->state == GAMEOVER)
                handle_replay(game, duk, player);
            else {
                start_game(game, player);
                if (duck_is_shot(game->window, duk))
                    player_on_kill(player);
            }
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
    return 0;
}

void clean_window(game_t *game)
{
    sfSprite_destroy(game->sprite_bg);
    sfRenderWindow_destroy(game->window);
    free(game);
}
