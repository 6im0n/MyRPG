/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"
#include <stdbool.h>

void inventory_object_add_id(node_component_t *node)
{
    for (int i = 0; i <= ID_SLOT_8 - 1; i++) {
        node->id = ID_SLOT_1 + i;
        node = node->prev;
    }
}

static void set_feature(node_component_t *component,
sfIntRect intrect, sfFloatRect rect, component_styles style)
{
    component->features.styles = style;
    component->features.rendered_rect = rect;
    component->features.size = C_SIZE_MEDIUM;
    component->features.texture_rect = intrect;
    component->features.select = false;
    component->features.radius = 0;
}

void new_component_set(node_component_t *component,
sfFloatRect rect, component_type_t type, component_styles style)
{
    sfIntRect intrect = {0, 0, 0, 0};

    if (!component)
        return;
    component->object = malloc(sizeof(renderer_objects_t));
    set_feature(component, intrect, rect, style);
    component->annimation.index = 0;
    component->annimation.max = 0;
    component->annimation.speed = 0;
    component->annimation.one = false;
    component->annimation.rect = intrect;
    component->id = ID_UNDEFINED;
    component->type = type;
    component->state = 0;
    component->next = NULL;
    component->events = (component_events_t) { NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL };
}
