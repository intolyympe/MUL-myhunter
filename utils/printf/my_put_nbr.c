/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** put nbr pour mini_printf
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int i = 0;
    int divisor = 1;
    int quotient = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        i++;
    }
    while (nb / divisor >= 10) {
        divisor *= 10;
    }
    while (divisor != 0) {
        quotient = nb / divisor;
        my_putchar(quotient + '0');
        nb %= divisor;
        divisor /= 10;
        i++;
    }
    return i;
}
