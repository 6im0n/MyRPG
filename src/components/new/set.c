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
    if (!component)
        return;
    component->object = malloc(sizeof(renderer_objects_t));
    component->texture = texture;
    component->type = type;
    component->rendered_rect = rect;
    component->state = 0;
    component->next = NULL;
    component->events = (component_events_t) { NULL, NULL, NULL, NULL, NULL };
}
