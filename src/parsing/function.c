/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** functions
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "lib/str.h"
#include "utils/file.h"
#include "types/type.h"
#include "types/list.h"
#include "components/new.h"
#include "components/components.h"
#include "event/start_menu/bouton.h"
#include "event/functions.h"

void get_clicked(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.clicked == CLICKED_LEN) {
        element->function.clicked = number;
        return;
    }
}

void get_hover(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.hover == HOVER_LEN) {
        element->function.hover = number;
        return;
    }
}

void get_disabled(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.disabled == DISABLED_LEN) {
        element->function.disabled = number;
        return;
    }
}

void get_moved(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->function.moved == MOVED_LEN) {
        element->function.moved = number;
        return;
    }
}
