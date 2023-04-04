/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** inventory
*/

#include "types/type.h"
#include "types/list.h"

static void list_items_copy(list_item_t *list, node_item_t *node)
{
    node_item_t *item = item_pure_new();

    item->frect = node->frect;
    item->irect = node->irect;
    item->item = node->item;
    item->shape = sfRectangleShape_copy(node->shape);
    list_item_append(list, item);
}

void add_item_player(app_t *app, item_t item)
{
    node_item_t *tmp = app->element->items->first;
    node_item_t *tmp2 = tmp;

    if (!tmp)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->item == item)
            list_items_copy(app->element->player->inventory, tmp);
        tmp = tmp2;
    }
}
