/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"
#include "app/constants.h"

void event_settings_resolution_onhover(node_component_t *component,
event_t *event, app_t *app)
{
    sfVector2f middle =
        sfRectangleShape_getPosition(component->object->rectangle);
    sfVector2f position = {middle.x, 740 };
    sfVector2f positiontext = {middle.x, 730 };

    (void) event;
    (void) app;
    component->features.texture_rect.top = 155;
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfText_setPosition(component->object->text, positiontext);
}

void event_settings_resolution_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    sfVector2f middle =
        sfRectangleShape_getPosition(component->object->rectangle);
    sfVector2f position = {middle.x, 750 };
    sfVector2f positiontext = {middle.x, 740 };

    (void) event;
    (void) app;
    component->features.texture_rect.top = 11;
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfText_setPosition(component->object->text, positiontext);
}
