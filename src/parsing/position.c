/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** position
*/

#include <SFML/Graphics.h>
#include "lib/str.h"
#include "app/constants.h"
#include "event/functions.h"

void get_rect(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->rect.left == -1) {
        element->rect.left = number;
        return;
    }
    if (element->rect.top == -1) {
        element->rect.top = number;
        return;
    }
    if (element->rect.width == -1) {
        element->rect.width = number;
        return;
    }
    if (element->rect.height == -1) {
        element->rect.height = number;
        return;
    }
}

void get_position(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (nb[0] == '.') {
        if (element->position.x == -1)
            element->position.x = W_VIDEO_MODE.width * (number / 100.0);
        else
            element->position.y = W_VIDEO_MODE.height * (number / 100.0);
    } else {
        if (element->position.x == -1)
            element->position.x = number;
        else
            element->position.y = number;
    }
}
