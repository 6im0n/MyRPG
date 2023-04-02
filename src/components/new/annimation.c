/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** text set
*/

#include "components/components.h"
#include <stdbool.h>

void new_component_annimation(node_component_t *component,
sfIntRect annimation, int index, int max)
{
    if (!component)
        return;
    component->object->clock = sfClock_create();
    component->annimation.index = index;
    component->annimation.max = max;
    component->annimation.rect = annimation;
}
