/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/list.h"


list_mobs_t *mob_add(list_mobs_t *list, ressources_t ressources)
{
    node_mob_t *mob = node_mob_init(ressources);

    if (!mob)
        return NULL;
    list_mob_append(list, mob);
    return list;
}
