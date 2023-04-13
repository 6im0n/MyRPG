/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include <stdlib.h>
#include "components/mobs.h"

node_mob_t *node_mobs_init(ressources_t ressources)
{
    node_mob_t *tmp = malloc(sizeof(node_mob_t));
    sfIntRect rect = {0, 0, 0, 0};

    if (!tmp)
        return 0;
    sfFloatRect frect = {0, 0, 0, 0};
    sfIntRect irect = {0, 0, 0, 0};
    tmp->texture = ressources.textures[TX_APP_ICON];
    tmp->shape = sfRectangleShape_create();
    tmp->frect = frect;
    tmp->irect = irect;
    tmp->annimation = (mobs_annimation_t){rect, 0, 0, 0, 0};
    tmp->state = 0;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
