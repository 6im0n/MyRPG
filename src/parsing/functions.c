/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** functions
*/

#include <SFML/Graphics.h>
#include "lib/str.h"
#include "event/functions.h"

void get_pressed(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.pressed == KEYPRESSED_LEN) {
        element->function.pressed = number;
        return;
    }
}

void get_released(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.released == KEYRELEASED_LEN) {
        element->function.released = number;
        return;
    }
}

void get_next_to(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.next_to == NEXT_TO_LEN) {
        element->function.next_to = number;
        return;
    }
}
