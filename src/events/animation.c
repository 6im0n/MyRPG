/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** annimation
*/


#include "components/components.h"

void event_active_annimation(node_component_t *component,
event_t *event, app_t *app)
{
    (void)app;
    (void)event;
    component->annimation.speed = component->annimation.max_speed;
    sfText_setColor(component->object->text, sfBlack);
}

void event_disabled_annimation(node_component_t *component,
event_t *event, app_t *app)
{
    sfIntRect rect = component->features.texture_rect;

    (void)app;
    (void)event;
    component->annimation.speed = 0;
    component->annimation.index = 0;
    rect.left = 0;
    if (component->type == C_TYPES_SIGN)
        sfRectangleShape_setTextureRect(component->object->rectangle,
        rect);
    sfText_setColor(component->object->text, sfTransparent);
}

void event_pause_annimation(node_component_t *component,
event_t *event, app_t *app)
{
    (void)app;
    (void)event;
    component->annimation.speed = 0;
    sfText_setColor(component->object->text, sfTransparent);
}
