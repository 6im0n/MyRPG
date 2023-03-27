/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** strtoint
*/

#include "str.h"

static int handle_digit(char digit, long *nbr, short *sign, short *find_state)
{
    if ((!*find_state && digit != '0') || *find_state) {
        *nbr = *nbr * 10 + (digit - '0');
        if ((*sign > 0 && *nbr > 2147483647)
            || (*sign < 0 && -(*nbr) < -2147483648)) {
            *nbr = 0;
            return (0);
        }
    }
    return (1);
}

static void handle_sign(char s, short *sign)
{
    if (s == '-'){
        *sign = *sign * -1;
    }
    return;
}

static int check_continue(short *sign, short find_state)
{
    if (find_state) {
        return (0);
    } else {
        *sign = 1;
        return (1);
    }
}

static int handle_char(char c, short *sign, long *nbr, short *find_state)
{
    short r = 1;
    if ((c == '-' || c == '+') && !(*find_state)) {
        handle_sign(c, sign);
        r = 1;
    } else if (c >= '0' && c <= '9') {
        r = handle_digit(c, nbr, sign, find_state);
        *find_state = 1;
    } else {
        r = check_continue(sign, *find_state);
    }
    return r;
}

int my_strtoint(char const *str)
{
    short sign = 1;
    short find_state = 0;
    int len = my_strlen(str);
    long nbr = 0;

    for (int i = 0; i < len; i++) {
        i = handle_char(str[i], &sign, &nbr, &find_state) ? i : len;
    }
    return sign * nbr;
}
