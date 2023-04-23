/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** inventory
*/

#include "types/type.h"
#include "types/list.h"
#include "lib/output.h"
#include "app/app.h"

static void list_items_copy(list_item_t *list, node_item_t *node)
{
    node_item_t *item = item_pure_new();

    if (list->len > 0)
        item->slot = list->last->slot + 1;
    else
        item->slot = ID_SLOT_1;
    item->frect = node->frect;
    item->irect = node->irect;
    item->item = node->item;
    item->name = node->name;
    item->sharpness = node->sharpness;
    item->weight = node->weight;
    item->shape = sfRectangleShape_copy(node->shape);
    list_item_append(list, item);
}

void add_item_player(app_t *app, item_t item)
{
    node_item_t *first = app->element->player->inventory->first;
    node_item_t *tmp = app->element->items->first;
    node_item_t *tmp2 = tmp;

    new_popup(app, P_ITEM, 5);
    if (first && item != I_NONE && first->item == I_NONE)
        list_remove(app->element->player->inventory, first);
    if (!tmp || app->element->player->inventory->len > 8)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->item == item)
            list_items_copy(app->element->player->inventory, tmp);
        tmp = tmp2;
    }
}
