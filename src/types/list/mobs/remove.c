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

void mob_list_destroy(list_mobs_t *list)
{
    list_mob_free(list);
}

static void node_mob_unlink(node_mob_t *node)
{
    if (!node)
        return;
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
}

void list_mob_remove(list_mobs_t *list, node_mob_t *node)
{
    node_mob_unlink(node);
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
        if (!mob_next_to_player(app, tmp, tmp->radius + 100)) {
            sfRectangleShape_destroy(tmp->obj_shape);
            sfClock_destroy(tmp->clock);
            list_mob_remove(list, tmp);
            free(tmp);
        }
        tmp = tmp2;
    }
}
