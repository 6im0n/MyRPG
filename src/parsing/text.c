/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** text
*/

#include "components/components.h"
#include "lib/str.h"

void get_text(char *text, parsing_t *element)
{
    if (element->text == NULL)
        element->text = my_strdup(text);
}

void get_text_size(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->text_size == -1) {
        element->text_size = number;
        return;
    }
}

void get_text_pos(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->text_pos.x == -1) {
        element->text_pos.x = number;
        return;
    }
    if (element->text_pos.y == -1) {
        element->text_pos.y = number;
        return;
    }
}

void get_text_pos_type(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->text_pos_type == -1) {
        element->text_pos_type = number;
        return;
    }
}
