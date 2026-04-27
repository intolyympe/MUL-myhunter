/*
** EPITECH PROJECT, 2024
** flag c
** File description:
** flag for 'c'
*/
#include "../../include/my.h"
#include <stdarg.h>

int flag_c(va_list list)
{
    return my_putchar(va_arg(list, int));
}
