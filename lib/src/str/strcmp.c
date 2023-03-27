/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** strcmp
*/

#include "str.h"
#include "output.h"

static char get_i_char(char const *str, int i, int len)
{
    if (i < len) {
        return str[i];
    } else {
        return (0);
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = 0;
    int len_s2 = 0;
    char cs1 = 0;
    char cs2 = 0;
    int i = 0;

    if (!s1 || !s2)
        return -1;
    len_s1 = my_strlen(s1);
    len_s2 = my_strlen(s2);
    while (i < len_s1 || i < len_s2) {
        cs1 = get_i_char(s1, i, len_s1);
        cs2 = get_i_char(s2, i, len_s2);
        if (cs1 - cs2 != 0) {
            return (cs1 - cs2);
        }
        i++;
    }
    return (0);
}
