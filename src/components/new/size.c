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
    if (rect.width != 0 && rect.height != 0)
        sfRectangleShape_setTextureRect(component->object->rectangle, rect);
    sfRectangleShape_setSize(component->object->rectangle, size);
    component->features.rendered_rect =
    sfRectangleShape_getGlobalBounds(component->object->rectangle);
}

static void init_circle(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    if (!component)
        return;
    if (rect.width != 0 && rect.height != 0)
        sfCircleShape_setTextureRect(component->object->circle, rect);
    sfCircleShape_setRadius(component->object->circle, size.x);
    component->features.rendered_rect =
    sfCircleShape_getGlobalBounds(component->object->circle);
}

static void init_sprite(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    if (!component)
        return;
    if (rect.width != 0 && rect.height != 0)
        sfSprite_setTextureRect(component->object->sprite, rect);
    sfSprite_setScale(component->object->sprite, size);
    component->features.rendered_rect =
    sfSprite_getGlobalBounds(component->object->sprite);
}

static void init_text(node_component_t *component,
sfVector2f size, sfIntRect rect)
{
    (void) rect;
    if (!component)
        return;
    sfText_setCharacterSize(component->object->text, size.x);
    component->features.rendered_rect =
    sfText_getGlobalBounds(component->object->text);
}

void new_component_size(node_component_t *component,
sfVector2f size, sfIntRect rect, component_size_t e_size)
{
    component->features.texture_rect = rect;
    component->features.size = e_size;
    switch (component->type) {
        case C_TYPES_RECTANGLE:
        case C_TYPES_BUTTON:
            init_rectangle(component, size, rect);
            break;
        case C_TYPES_CIRCLE:
            init_circle(component, size, rect);
            break;
        case C_TYPES_SPRITE:
            init_sprite(component, size, rect);
            break;
        case C_TYPES_TEXT:
            init_text(component, size, rect);
            break;
        default:
            break;
    }
}
