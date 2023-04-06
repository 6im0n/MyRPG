/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** remove
*/

#include "components/player.h"
#include "types/list.h"

static void move_id_slot(list_item_t *list, component_id_t slot)
{
    node_item_t *tmp = list->first;
    node_item_t *tmp2 = tmp;

    if (slot > list->last->slot)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->slot > slot)
            tmp->slot--;
        tmp = tmp2;
    }
}

static void remove_middle_slot(list_item_t *list, node_item_t *node)
{
    node_item_t *tmp = list->first;
    node_item_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->slot == node->slot) {
            list_remove(list, tmp);
            move_id_slot(list, tmp->slot);
            return;
        }
        tmp = tmp2;
    }
}

static void delete(list_item_t *list, node_item_t *node)
{
    bool changed = false;

    if (list->last->slot == node->slot) {
        list->last = node->prev;
        list->last->next = NULL;
        list->len--;
        changed = true;
    }
    if (list->first->slot == node->slot) {
        list->first = node->next;
        list->first->prev = NULL;
        list->len--;
        move_id_slot(list, node->slot);
        changed = true;
    }
    if (changed == false)
        remove_middle_slot(list, node);
}

void list_item_delete(list_item_t *list, component_id_t slot)
{
    node_item_t *tmp = list->first;
    node_item_t *tmp2 = tmp;

    if (list->len <= 1 || slot > list->last->slot)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->slot == slot)
            return delete(list, tmp);
        tmp = tmp2;
    }
}
