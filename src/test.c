/*
** EPITECH PROJECT, 2024
** test sfml
** File description:
** test sfml
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

sfSprite *create_sprite1(char *filepath)
{
    sfSprite* sprite1 = sfSprite_create();
    sfTexture* texture1 = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite1, texture1, sfTrue);
    sfIntRect rect = {0, 0, 110, 110};
    sfSprite_setTextureRect(sprite1, rect);
    rect.left += 110;
    rect.left %= 330;
    return sprite1;
}

sfSprite *create_sprite2(char *filepath)
{
    sfSprite* sprite2 = sfSprite_create();
    sfTexture* texture2 = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    return sprite2;
}

//int events(sfRenderWindow *window, sfEvent *event)
//{
  //  sfVector2i mouse_position;
//
  //      while (sfRenderWindow_pollEvent(window, event)) {
    //    if (sfMouse_isButtonPressed(sfMouseLeft)) {
      //      mouse_position = sfMouse_getPositionRenderWindow(window);
        //    printf("x = %d\ny = %d\n", mouse_position.x, mouse_position.y);
        //}
        //if (event->type == sfEvtClosed)
          //  sfRenderWindow_close(window);
    //}
    //return 0;
//}

int main(void)
{
    sfVideoMode mode = {736, 552, 32};
    sfRenderWindow* window;
    sfSprite* sprite1 = create_sprite1("img/duck.png");
    sfSprite* sprite2 = create_sprite2("img/background1.jpeg");
    sfEvent event;

    //sfClock *clock = sfClock_create();
    //sfIntRect rect;

    //sfVector2f bird_position;
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        //sfSprite_move(sprite1, bird_position);
        if (events(window, &event))
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite2, NULL);
        sfRenderWindow_drawSprite(window, sprite1, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite1);
    sfSprite_destroy(sprite2);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}