/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** animation
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

void get_anim_rect(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->animation.rect.left == -1) {
        element->animation.rect.left = number;
        return;
    }
    if (element->animation.rect.top == -1) {
        element->animation.rect.top = number;
        return;
    }
    if (element->animation.rect.width == -1) {
        element->animation.rect.width = number;
        return;
    }
    if (element->animation.rect.height == -1) {
        element->animation.rect.height = number;
        return;
    }
}

void get_anim_index(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->animation.index == -1) {
        element->animation.index = number;
        return;
    }
}

void get_anim_max(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->animation.max == -1) {
        element->animation.max = number;
        return;
    }
}

void get_anim_speed(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->animation.speed == -1) {
        element->animation.speed = number / 100.0;
        return;
    }
}
