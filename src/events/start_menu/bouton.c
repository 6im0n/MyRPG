/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"

void event_bouton_play_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    sfRectangleShape_setScale(component->object->rectangle, (sfVector2f){0.8, 0.8});
}
