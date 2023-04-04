/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include <stdlib.h>
#include "components/player.h"

node_item_t *item_pure_new(void)
{
    node_item_t *component = malloc(sizeof(node_item_t));
    sfFloatRect frect = { 0, 0, 0, 0};
    sfIntRect irect = { 0, 0, 0, 0};

    if (!component)
        return NULL;
    component->frect = frect;
    component->irect = irect;
    component->item = I_NONE;
    component->prev = NULL;
    component->shape = sfRectangleShape_create();
    component->next = NULL;
    return component;
}

list_item_t *list_item_init(void)
{
    list_item_t *tmp = malloc(sizeof(list_item_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_item_free(list_item_t *list)
{
    node_item_t *tmp = list->first;
    node_item_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
