/*
** EPITECH PROJECT, 2024
** flag_percent
** File description:
** flag for '%'
*/
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

int flag_percent(va_list list)
{
    (void)list;
    return my_putchar('%');
}