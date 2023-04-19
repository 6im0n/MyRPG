/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** node
*/

#include <stdlib.h>
#include "types/type.h"

node_layer_t *layer_node_init(void)
{
    node_layer_t *tmp = malloc(sizeof(node_layer_t));

    if (!tmp)
        return NULL;
    tmp->id = ID_UNDEFINED;
    tmp->frect = (sfFloatRect){0, 0, 0, 0};
    tmp->irect = (sfIntRect){0, 0, 0, 0};
    tmp->obj = sfRectangleShape_create();
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
