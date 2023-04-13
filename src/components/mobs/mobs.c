/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/list.h"


list_mobs_t *mobs_add(list_mobs_t *list, ressources_t ressources)
{
    node_mob_t *mob = node_mobs_init(ressources);

    if (!mob)
        return NULL;
    list_mobs_append(list, mob);
    return list;
}

void mobs_destroy(list_mobs_t *list)
{
    list_mobs_free(list);
}
