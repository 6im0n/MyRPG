/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include <stdlib.h>
#include "types/type.h"

list_layer_t *list_layers_init(void)
{
    list_layer_t *tmp = malloc(sizeof(list_layer_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_layers_free(list_layer_t *list)
{
    node_layer_t *tmp = list->first;
    node_layer_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfRectangleShape_destroy(tmp->obj);
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
