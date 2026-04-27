/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

static const flag_t tab_format[] = {
    {'c', flag_c},
    {'d', flag_d},
    {'i', flag_d},
    {'t', flag_d},
    {'s', flag_s},
    {'%', flag_percent},
    {'\0', NULL}
};

int w_flags(char flag, va_list list, const flag_t *tab_format)
{
    int i = 0;

    while (tab_format[i].flag != '\0') {
        if (tab_format[i].flag == flag) {
            tab_format[i].function(list);
            return 1;
        }
        i++;
    }
    my_putchar('%');
    return 2;
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    va_list list;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i +1] != '\0') {
            i++;
            count += w_flags(format[i], list, tab_format);
        } else {
            count += my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return count;
}
