/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** curosr
*/

#include "types/types.h"
#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"

void event_cursor_onmove(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    node_component_t *tmp = component->next;
    sfVector2f position = {
        app->mouse.position.x + 12,
        app->mouse.position.y + 14.5};

    sfRectangleShape_setPosition(tmp->object->rectangle, position);
    tmp->features.rendered_rect =
    sfRectangleShape_getGlobalBounds(tmp->object->rectangle);
}
