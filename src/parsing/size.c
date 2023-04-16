/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** size
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "lib/str.h"
#include "event/functions.h"
#include "app/constants.h"

void get_c_size(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->c_size == C_SIZE_LEN) {
        element->c_size = number;
        return;
    }
}

void get_radius(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->radius == 0) {
        element->radius = number;
        return;
    }
}

void get_size(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (nb[0] == '.') {
        if (element->size.x == -1)
            element->size.x = W_VIDEO_MODE.width * (number / 100.0);
        else
            element->size.y = W_VIDEO_MODE.height * (number / 100.0);
    } else {
        if (element->size.x == -1)
            element->size.x = number;
        else
            element->size.y = number;
    }
}
