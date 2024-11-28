/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-leslye1.jeannin
** File description:
** my_int_to_str.c
*/
#include <stdio.h>
#include <stdlib.h>

int length(int nb)
{
    int count = 0;
    int i = 0;
    int divisor = 1;

    while (nb / divisor >= 10) {
        divisor *= 10;
    }
    while (divisor != 0) {
        count++;
        nb %= divisor;
        divisor /= 10;
        i++;
    }
    return count;
}

char *my_int_to_str(int nb)
{
    char *str = NULL;
    int i = 0;
    int divisor = 1;
    int quotient = 0;

    str = malloc(sizeof(char) * (length(nb) + 1));
    while (nb / divisor >= 10) {
        divisor *= 10;
    }
    while (divisor != 0) {
        quotient = nb / divisor;
        nb %= divisor;
        divisor /= 10;
        str[i] = quotient + '0';
        i++;
    }
    str[i] = '\0';
    return str;
}