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
    tmp->state.left = false;
    tmp->radius = 0;
}

static void init_healt(node_mob_t *tmp)
{
    tmp->healt.outline = NULL;
    tmp->healt.frect = (sfFloatRect){0, 0, 0, 0};
    tmp->healt.curent = 100;
    tmp->healt.max = 100;
    tmp->healt.bar = sfRectangleShape_create();
    tmp->healt.outline = sfRectangleShape_create();
    tmp->time_hited.microseconds = 0;
    tmp->cooldown.microseconds = 0;
    tmp->time.microseconds = 0;
}

static void init_animation(node_mob_t *tmp)
{
    tmp->annimation.index = 0;
    tmp->annimation.max = 0;
    tmp->annimation.max_speed = 0;
    tmp->annimation.rect = (sfIntRect){0, 0, 0, 0};
    tmp->annimation.speed = 0;
}

node_mob_t *node_mob_init(ressources_t ressources)
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
    tmp->annimation = (mobs_annimation_t){rect, 0, 0, 0, 0};
    init_state(tmp);
    tmp->clock = NULL;
    init_animation(tmp);
    tmp->skills = (skills_t){0, 0, 0};
    tmp->next = NULL;
    tmp->prev = NULL;
    init_healt(tmp);
    return tmp;
}
