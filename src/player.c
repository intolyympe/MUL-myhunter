/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** player.c
*/

#include "../include/hunter.h"
#include "../include/my.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->life = 4;
    player->score = 0;
    player->sprite_life = sfSprite_create();
    player->texture_life = sfTexture_createFromFile("img/life1.png", NULL);
    player->rect_life.left = 0;
    player->rect_life.top = 240;
    player->rect_life.width = 330;
    player->rect_life.height = 72;
    sfSprite_setTexture(player->sprite_life, player->texture_life, sfTrue);
    sfSprite_setTextureRect(player->sprite_life, player->rect_life);
    sfSprite_setPosition(player->sprite_life, (sfVector2f){1550, 15});
    player->text = sfText_create();
    player->font = sfFont_createFromFile("utils/font/Bubblegum.ttf");
    sfText_setString(player->text, my_int_to_str(player->score));
    sfText_setPosition(player->text, (sfVector2f){10, 10});
    sfText_setFont(player->text, player->font);
    sfText_setCharacterSize(player->text, 25);
    return player;
}

void clean_player(player_t *player)
{
    sfText_destroy(player->text);
    free(player);
}

void player_on_escape(player_t *player)
{
    player->rect_life.top -= 78;
    player->life -= 1;
    sfSprite_setTextureRect(player->sprite_life, player->rect_life);
}

void player_on_kill(player_t *player)
{
    player->score += 100;
    sfText_setString(player->text, my_int_to_str(player->score));
}
