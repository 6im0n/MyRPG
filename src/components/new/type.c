/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "components/components.h"

static void set_sound(ressources_t ressources, node_component_t *component)
{
    if (component->features.styles.sound == SD_NONE)
        return;
    component->object->sound = sfSound_create();
    sfSound_setBuffer(
        component->object->sound,
        ressources.sounds[SD_GRAB]);
}

static void init_rectangle(node_component_t *component,
ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[
        component->features.styles.texture];
    sfVector2f origin = {
        component->features.rendered_rect.width / 2,
        component->features.rendered_rect.height / 2};

    component->object->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfRectangleShape_setTexture(component->object->rectangle,
        texture, sfFalse);
    sfRectangleShape_setOrigin(component->object->rectangle, origin);
    // sfRectangleShape_setOutlineColor(component->object->rectangle, sfRed);
    // sfRectangleShape_setOutlineThickness(component->object->rectangle, 2);
    set_sound(ressources, component);
}

static void init_circle(node_component_t *component,
ressources_t ressources, sfVector2f position)
{
    sfTexture *texture = ressources.textures[
        component->features.styles.texture];
    float size = (sfTexture_getSize(texture).x / 2);

    component->object->circle = sfCircleShape_create();
    sfCircleShape_setPosition(component->object->circle, position);
    sfCircleShape_setTexture(component->object->circle, texture, sfFalse);
    sfCircleShape_setRadius(component->object->circle, size);
}

static void init_text(node_component_t *component,
ressources_t ressources, sfVector2f position)
{
    sfFont *font = ressources.fonts[
        component->features.styles.font];

    component->object->text = sfText_create();
    sfText_setFont(component->object->text, font);
    sfText_setPosition(component->object->text, position);
}

void new_component_type(ressources_t ressources,
node_component_t *component, sfVector2f position)
{
    switch (component->type) {
        case C_TYPES_BUTTON:
        case C_TYPES_RECTANGLE:
            init_rectangle(component, ressources, position);
            break;
        case C_TYPES_CIRCLE:
            init_circle(component, ressources, position);
            break;
        case C_TYPES_TEXT:
            init_text(component, ressources, position);
            break;
        case C_TYPES_SIGN:
        case C_TYPES_BTN_TXT:
            init_text(component, ressources, position);
            init_rectangle(component, ressources, position);
            break;
        default:
            break;
    }
}
