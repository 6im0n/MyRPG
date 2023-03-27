/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** strdup
*/

#include <stdlib.h>
#include "str.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char)* (len + 1));

    if (!str)
        return NULL;
    my_strcpy(str, src);

    return str;
}
