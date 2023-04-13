/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/list.h"


list_mobs_t *mobs_add(list_mobs_t *mobs_list, ressources_t ressources)
{
    node_mobs_t *mobs = node_mobs_init(ressources);
    
    if (!mobs)
        return NULL;
    list_mobs_append(mobs_list, mobs);
    return mobs_list;
}

void mobs_destroy(list_mobs_t *mobs)
{
    list_mobs_free(mobs);
}
