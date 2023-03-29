/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"

static void init_rectangle(node_component_t *component,
ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[component->texture];
    sfVector2f origin = {
        component->rendered_rect.width / 2,
        component->rendered_rect.height / 2};

    component->object->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfRectangleShape_setOrigin(component->object->rectangle, origin);
    sfRectangleShape_setTexture(component->object->rectangle,
        texture, sfFalse);
    sfRectangleShape_setOutlineColor(component->object->rectangle, sfRed);
    sfRectangleShape_setOutlineThickness(component->object->rectangle, 2);
}

static void init_circle(node_component_t *component,
ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[component->texture];
    float size = (sfTexture_getSize(texture).x / 2);

    component->object->circle = sfCircleShape_create();
    sfCircleShape_setPosition(component->object->circle, position);
    sfCircleShape_setTexture(component->object->circle, texture, sfFalse);
    sfCircleShape_setRadius(component->object->circle, size);
}

static void init_sprite(node_component_t *component,
ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[component->texture];

    component->object->sprite = sfSprite_create();
    sfSprite_setPosition(component->object->sprite, position);
    sfSprite_setTexture(component->object->sprite, texture, sfFalse);
}

void new_component_type(ressources_t ressources,
node_component_t *component, renderer_objects_t objects,
sfVector2f position)
{
    (void) objects;
    switch (component->type) {
        case C_TYPES_RECTANGLE:
            init_rectangle(component, ressources, position);
            break;
        case C_TYPES_CIRCLE:
            init_circle(component, ressources, position);
            break;
        case C_TYPES_TEXT:
            component->object->text = objects.text;
            break;
        case C_TYPES_SPRITE:
            init_sprite(component, ressources, position);
            break;
        default:
            break;
    }
}
