/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** size
*/

#include <SFML/Graphics.h>
#include "lib/str.h"
#include "event/functions.h"

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

void get_size(char *nb, parsing_t *element, app_t *app)
{
    int number = 0;

    number = my_strtoint(nb);
    if (nb[0] == '.') {
        if (element->size.x == -1)
            element->size.x =
            sfRenderWindow_getSize(app->window).x * (number / 100.0);
        else
            element->size.y =
            sfRenderWindow_getSize(app->window).y * (number / 100.0);
    } else {
        if (element->size.x == -1)
            element->size.x = number;
        else
            element->size.y = number;
    }
}
