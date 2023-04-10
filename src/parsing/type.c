/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** type
*/

#include <SFML/Graphics.h>
#include "lib/str.h"
#include "components/components.h"

void get_style(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->style.texture == TX_LEN) {
        element->style.texture = number;
        return;
    }
    if (element->style.sound == SD_LEN) {
        element->style.sound = number;
        return;
    }
    if (element->style.font == FT_LEN) {
        element->style.font = number;
        return;
    }
}

void get_type(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->type == C_TYPES_LEN) {
        element->type = number;
        return;
    }
}
