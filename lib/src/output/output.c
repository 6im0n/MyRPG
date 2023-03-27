/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** output
*/

#include "str.h"
#include <unistd.h>

ssize_t my_putstr(char const *str, int output)
{
    return write(output, str, my_strlen(str));
}

int my_put_nbr(int nb)
{
    char n = 0;

    if (nb < 0) {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    n = nb % 10 + '0';
    write(1, &n, 1);
    return 1;
}
