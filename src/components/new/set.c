/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"

void new_component_set(node_component_t *component,
sfFloatRect rect, component_type_t type, texture_t texture)
{
    sfIntRect intrect = {0, 0, 0, 0};

    if (!component)
        return;
    component->object = malloc(sizeof(renderer_objects_t));
    component->features.texture = texture;
    component->features.rendered_rect = rect;
    component->features.size = C_SIZE_MEDIUM;
    component->features.texture_rect = intrect;
    component->type = type;
    component->state = 0;
    component->next = NULL;
    component->events = (component_events_t) { NULL, NULL, NULL, NULL, NULL };
}
