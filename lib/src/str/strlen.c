/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** strlen
*/

#include <unistd.h>

size_t my_strlen(char const *str)
{
    size_t len = 0;

    while (*str != '\0') {
        str++;
        len++;
    }
    return (len);
}
