/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** layers
*/

#include "types/type.h"

void layer_render(app_t *app)
{
    node_layer_t *tmp = app->element->layers->first;

    while (tmp) {
        sfRenderWindow_drawRectangleShape(app->window, tmp->obj, NULL);
        tmp = tmp->next;
    }
}
