/*
** EPITECH PROJECT, 2024
** flag_d
** File description:
** flag for 'd'or 'i'
*/
#include "../../include/my.h"
#include <stdarg.h>

int flag_d(va_list list)
{
    return my_put_nbr(va_arg(list, int));
}
