/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** sprite.c
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

sfSprite *create_background(char *filepath)
{
    sfSprite* sprite2 = sfSprite_create();
    sfTexture* texture2 = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite2, texture2, sfTrue);
    return sprite2;
}

sfSprite *create_ground(char *filepath)
{
    sfSprite* sprite3 = sfSprite_create();
    sfTexture* texture3 = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite3, texture3, sfTrue);
    return sprite3;
}

/*sfSprite *animate_sprite(char *filepath)
{
    //sfIntRect rect = sfSprite_getTextureRect(create_sprite1(filepath));
    sfIntRect rect = {0, 0, 110, 110};
    sfSprite_setTextureRect(create_sprite1(filepath), rect);

    rect.left += 110;
    if (rect.left >= 220)
        rect.left = 0;
    sfSprite_setTextureRect(create_sprite1(filepath), rect);
    return create_sprite1(filepath);
}
*/
