/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse str.
*/

#include "tools.h"
#include <stdlib.h>
#include "str.h"

static int my_power(int nb ,int b)
{
    float power = 1.00;

    if (b < 0) {
        b = -1 * b;
        nb = 1 / nb;
    }
    for ( int i = 1 ;i <= b ; ++i ) {
        power = power * nb ;
    }
    return power;
}

char *my_char(int get)
{
    char *dest = malloc(sizeof(char) * (my_nbrlen(get) + 1));
    int len = my_nbrlen(get);
    int digit = 0;

    for (int i = 0; i < len; i++) {
        digit = get / my_power(10,len - i - 1);
        dest[i] = digit + '0';
        get %= my_power(10,len - i - 1);
    }
    dest[len] = '\0';
    return dest;
}

int my_int(char *get)
{
    int len = my_strlen(get);
    int digit = 0;
    int neg = 0;

    if (get[0] == '-') {
        get++;
        len--;
        neg++;
    }
    for (int i = 0; i < len; i++) {
        if (get[i] >= '0' && get[i] <= '9')
            digit = digit * 10 + (get[i] - '0');
        else
            return digit;
    }
    if (neg == 1)
        digit *= (-1);
    return digit;
}
