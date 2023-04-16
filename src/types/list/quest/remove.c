/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** remove
*/

#include "components/player.h"
#include "types/list.h"
#include <stdio.h>

static void node_unlink(node_quests_t *node)
{
    if (!node)
        return;
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
}

static void list_quest_remove(list_quests_t *list, node_quests_t *node)
{
    node_unlink(node);
    if (list->first == node)
        list->first = node->next;
    if (list->first)
        list->first->prev = NULL;
    if (list->last == node)
        list->last = node->prev;
    if (list->last)
        list->last->next = NULL;
    list->len--;
}

static void remove_middle_slot(list_quests_t *list, node_quests_t *node)
{
    node_quests_t *tmp = list->first;
    node_quests_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->id == node->id) {
            list_quest_remove(list, tmp);
            return;
        }
        tmp = tmp2;
    }
}

static void delete(list_quests_t *list, node_quests_t *node)
{
    bool changed = false;

    if (list->last->id == node->id) {
        list->last = node->prev;
        list->last->next = NULL;
        list->len--;
        changed = true;
    }
    if (list->first->id == node->id) {
        list->first = node->next;
        list->first->prev = NULL;
        list->len--;
        changed = true;
    }
    if (changed == false)
        remove_middle_slot(list, node);
}

void list_quest_delete(list_quests_t *list, quests_t id)
{
    node_quests_t *tmp = list->first;
    node_quests_t *tmp2 = tmp;

    if (list->len == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->len = 0;
        return;
    }
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->id == id)
            return delete(list, tmp);
        printf("%d\t%d\n", tmp->id, id);
        tmp = tmp2;
    }
}
