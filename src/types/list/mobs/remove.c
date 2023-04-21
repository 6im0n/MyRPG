/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** remove
*/

#include "components/player.h"
#include "types/list.h"
#include "lib/output.h"
#include "components/mobs.h"

#include <stdio.h>

static void node_unlinkt(node_mob_t *node)
{
    if (!node)
        return;
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
}

void list_removet(list_mobs_t *list, node_mob_t *node)
{
    node_unlinkt(node);
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

void list_mob_delete(app_t *app)
{
    list_mobs_t *list = app->element->mobs;
    node_mob_t *tmp = list->first;
    node_mob_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (!mobs_next_to_player(app, tmp, tmp->radius + 100)) {
            sfRectangleShape_destroy(tmp->obj_shape);
            sfClock_destroy(tmp->clock);
            list_removet(list, tmp);
            free(tmp);
        }
        tmp = tmp2;
    }
}
