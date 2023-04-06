/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** text set
*/

#include "components/components.h"
#include <stdbool.h>

static void annimation_edit(node_component_t *component)
{
    sfIntRect rect = component->features.texture_rect;
    sfIntRect rect_a = component->annimation.rect;

    rect_a.height *= component->annimation.index;
    rect_a.top *= component->annimation.index;
    rect_a.left *= component->annimation.index;
    rect_a.width *= component->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    switch (component->type) {
        case C_TYPES_SIGN:
            sfRectangleShape_setTextureRect(component->object->rectangle,
            rect);
            break;
        default:
            break;
    }
    component->annimation.index++;
}

void new_component_annimation(node_component_t *component,
sfIntRect annimation, int index, int max)
{
    if (!component)
        return;
    component->object->clock = sfClock_create();
    component->annimation.index = index;
    component->annimation.max = max;
    component->annimation.rect = annimation;
    annimation_edit(component);
}
