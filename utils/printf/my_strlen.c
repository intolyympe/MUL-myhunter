/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** length of a string
*/
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 1;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
