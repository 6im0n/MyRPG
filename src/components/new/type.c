/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"

static void init_rectangle(node_component_t *component,
renderer_objects_t objects, ressources_t ressources,
sfVector2f position)
{
    sfTexture *texture = ressources.textures[component->texture];
    sfVector2f size = {
        sfTexture_getSize(texture).x,
        sfTexture_getSize(texture).y};

    (void) objects;
    component->object->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfRectangleShape_setSize(component->object->rectangle, size);
    sfRectangleShape_setTexture(component->object->rectangle,
        texture, sfFalse);
}

static void init_circle(node_component_t *component,
renderer_objects_t objects, ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[component->texture];
    float size = (sfTexture_getSize(texture).x / 2);

    component->object->circle = objects.circle;
    sfCircleShape_setPosition(component->object->circle, position);
    sfCircleShape_setTexture(component->object->circle, texture, sfFalse);
    sfCircleShape_setRadius(component->object->circle, size);
}

static void init_sprite(node_component_t *component,
renderer_objects_t objects, ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[component->texture];

    component->object->circle = objects.circle;
    sfSprite_setPosition(component->object->sprite, position);
    sfSprite_setTexture(component->object->sprite, texture, sfFalse);
}

void new_component_type(ressources_t ressources,
node_component_t *component, renderer_objects_t objects,
sfVector2f position)
{
    switch (component->type) {
        case C_TYPES_RECTANGLE:
            init_rectangle(component, objects, ressources, position);
            break;
        case C_TYPES_CIRCLE:
            init_circle(component, objects, ressources, position);
            break;
        case C_TYPES_TEXT:
            component->object->text = objects.text;
            break;
        case C_TYPES_SPRITE:
            init_sprite(component, objects, ressources, position);
            break;
        default:
            break;
    }
}
