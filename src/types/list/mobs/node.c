/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include <stdlib.h>
#include "components/mobs.h"

static void init_state(node_mob_t *tmp)
{
    tmp->state.attack = false;
    tmp->state.walk = false;
    tmp->state.idle = false;
    tmp->state.die = false;
    tmp->state.hit = false;
}

static void init_healt(node_mob_t *tmp)
{
    tmp->healt.bar = NULL;
    tmp->healt.outline = NULL;
    tmp->healt.frect = (sfFloatRect){0, 0, 0, 0};
    tmp->healt.curent = 100;
    tmp->healt.max = 100;
    tmp->healt.bar = sfRectangleShape_create();
    tmp->healt.outline = sfRectangleShape_create();
}

node_mob_t *node_mobs_init(ressources_t ressources)
{
    node_mob_t *tmp = malloc(sizeof(node_mob_t));
    sfIntRect rect = {0, 0, 0, 0};
    sfFloatRect frect = {0, 0, 0, 0};
    sfIntRect irect = {0, 0, 0, 0};

    if (!tmp)
        return NULL;
    tmp->texture = ressources.textures[TX_APP_ICON];
    tmp->obj_shape = sfRectangleShape_create();
    tmp->frect = frect;
    tmp->irect = irect;
    tmp->time = sfTime_Zero;
    tmp->time_hit = sfTime_Zero;
    tmp->annimation = (mobs_annimation_t){rect, 0, 0, 0, 0};
    init_state(tmp);
    init_healt(tmp);
    tmp->radius = 0;
    tmp->skills = (skills_t){0, 0, 0};
    tmp->state = (mob_states_t){ false, false, false, false, false};
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
