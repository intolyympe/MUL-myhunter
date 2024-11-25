/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar pour mini_printf
*/

#include "../../include/my.h"
#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}