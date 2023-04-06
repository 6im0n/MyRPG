/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** position
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

void get_c_size(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->c_size == C_SIZE_LEN) {
        element->c_size = number;
        return;
    }
}
