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
    #include <unistd.h>

typedef enum game_state_t_s {
    MENU,
    GAME,
    GAMEOVER,
} game_state_t_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfSprite *sprite_bg;
    sfTexture *texture_bg;
    sfSprite *s_start;
    sfTexture *t_start;
    sfSprite *sprite_go;
    sfTexture *texture_go;
    game_state_t_t state;
} game_t;

typedef struct duck_s {
    sfSprite *sprite_duck;
    sfTexture *texture_duck;
    sfVector2f position;
    sfVector2f rand_value;
    sfVector2f vector;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *move_clock;
    int is_dead;
} duck_t;

typedef struct player_s {
    int score;
    int life;
    sfFont *font;
    sfText *text;
    sfSprite *sprite_life;
    sfTexture *texture_life;
    sfIntRect rect_life;
    sfVector2i mouse_position;
} player_t;

duck_t *init_duck(void);
game_t *init_window(void);
player_t *init_player(void);
void clean_duck(duck_t *duck);
void clean_player(player_t *player);
void clean_window(game_t *game);
int events(game_t *game, duck_t *duk, player_t *player);
int draw_sprite(game_t *game, duck_t *duk, player_t *player);
void start_game(game_t *game, player_t *player);
void animate_duck(duck_t *duck, sfClock *clock);
void move_duck(duck_t *duck, player_t *player);
void kill_duck(sfRenderWindow *window, duck_t *duck, player_t *player);

#endif
