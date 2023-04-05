/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** switch
*/

#include "components/player.h"
#include "lib/output.h"

static void prevent_first_last(list_item_t *list,
node_item_t *node1, node_item_t *node2)
{
    if (node1->prev == NULL)
        list->first = node2;
    if (node1->next == NULL)
        list->last = node2;
    if (node2->prev == NULL)
        list->first = node1;
    if (node2->next == NULL)
        list->last = node1;
}

static void swap_next_nodes(node_item_t *node1, node_item_t *node2)
{
    node_item_t tmp = *node1;

    node1->next = node2->next;
    node1->prev = node2;
    node2->next = node1;
    node2->prev = tmp.prev;
    if (node1->next != NULL)
        node1->next->prev = node1;
    if (node2->prev != NULL)
        node2->prev->next = node2;
}

static void swap_no_next_nodes(node_item_t *node1, node_item_t *node2)
{
    node_item_t tmp = *node1;

    node1->next = node2->next;
    node1->prev = node2->prev;
    if (node1->next != NULL)
        node1->next->prev = node1;
    if (node1->prev != NULL)
        node1->prev->next = node1;
    node2->next = tmp.next;
    node2->prev = tmp.prev;
    if (node2->next != NULL)
        node2->next->prev = node2;
    if (node2->prev != NULL)
        node2->prev->next = node2;
}

static void node_swap(list_item_t *list,
node_item_t *node1, node_item_t *node2)
{
    prevent_first_last(list, node1, node2);
    if (node1->next == node2 && node2->prev == node1)
        swap_next_nodes(node1, node2);
    else if (node2->next == node1 && node1->prev == node2)
        swap_next_nodes(node2, node1);
    else
        swap_no_next_nodes(node1, node2);
}

void swap_item_player(list_item_t *list,
component_id_t slot_1, component_id_t slot_2)
{
    component_id_t tmpid = ID_UNDEFINED;
    node_item_t *node1 = NULL;
    node_item_t *node2 = NULL;
    node_item_t *tmp = list->first;
    node_item_t *tmp2 = tmp;

    if (slot_1 > list->last->slot || slot_2 > list->last->slot)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->slot == slot_1)
            node1 = tmp;
        if (tmp->slot == slot_2)
            node2 = tmp;
        tmp = tmp2;
    }
    tmpid = node1->slot;
    node1->slot = node2->slot;
    node2->slot = tmpid;
    node_swap(list, node1, node2);
}
