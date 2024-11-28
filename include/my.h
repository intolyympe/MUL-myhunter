/*
** EPITECH PROJECT, 2024
** fichier.h for printf
** File description:
** files.h for printf
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stddef.h>

typedef struct defflag_s {
    char flag;
    int (*function)(va_list list);
} flag_t;

flag_t *format_tab(int);

int my_printf(const char *format, ...);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_int_to_str(int nb);

int flag_s(va_list list);
int flag_c(va_list list);
int flag_d(va_list list);
int flag_percent(va_list list);

#endif