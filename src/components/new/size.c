/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"

static void init_rectangle(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    if (!component)
        return;
    sfRectangleShape_setTextureRect(component->object->rectangle, rect);
    sfRectangleShape_setSize(component->object->rectangle, size);
}

static void init_circle(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    if (!component)
        return;
    sfCircleShape_setTextureRect(component->object->circle, rect);
    sfCircleShape_setRadius(component->object->circle, size.x);
}

static void init_sprite(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    if (!component)
        return;
    sfSprite_setTextureRect(component->object->sprite, rect);
    sfSprite_setScale(component->object->sprite, size);
}

void new_component_size(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    switch (component->type) {
        case C_TYPES_RECTANGLE:
            init_rectangle(component, size, rect);
            break;
        case C_TYPES_CIRCLE:
            init_circle(component, size, rect);
            break;
        case C_TYPES_SPRITE:
            init_sprite(component, size, rect);
            break;
        default:
            break;
    }
}
