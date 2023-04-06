/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** events_handlers
*/

#include <stdio.h>
#include "components/components.h"
#include "components/misc/events.h"

void component_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    component_handler_t handler = COMPONENT_ON_DISABLED(component);

    if (handler)
        handler(component, event, app);
}
