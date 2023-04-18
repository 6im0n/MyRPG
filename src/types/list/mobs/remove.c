/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** remove
*/

#include "components/player.h"
#include "types/list.h"
#include "lib/output.h"

void list_mob_delete(list_mobs_t *list)
{
    node_mob_t *tmp = list->first;
    node_mob_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfRectangleShape_destroy(tmp->shape);
        sfCircleShape_destroy(tmp->prox_shape);
        sfClock_destroy(tmp->clock);
        free(tmp);
        tmp = tmp2;
    }
    list->first = NULL;
    list->last = NULL;
    list->len = 0;
}
