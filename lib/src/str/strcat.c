/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** strcat
*/

#include "str.h"

void my_strcat(char *dest, const char *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
}
