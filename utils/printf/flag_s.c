/*
** EPITECH PROJECT, 2024
** flag_s
** File description:
** flag for 's'
*/

#include "../../include/my.h"
#include <stdarg.h>

int flag_s(va_list list)
{
    return my_putstr(va_arg(list, char *));
}