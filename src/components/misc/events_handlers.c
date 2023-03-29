/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** events_handlers
*/

#include <stdio.h>
#include "components/components.h"
#include "components/misc/events.h"

void component_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    component_handler_t handler = COMPONENT_ON_CLICK(component);

    if (ST_IS_DISABLED(component))
        return;
    if (handler)
        handler(component, event, app);
}

void component_onhover(node_component_t *component,
event_t *event, app_t *app)
{
    component_handler_t handler = COMPONENT_ON_HOVER(component);

    if (handler)
        handler(component, event, app);
}

void component_onmove(node_component_t *component,
event_t *event, app_t *app)
{
    component_handler_t handler = COMPONENT_ON_MOVE(component);

    if (handler)
        handler(component, event, app);
}

void component_onnonclick(node_component_t *component,
event_t *event, app_t *app)
{
    component_handler_t handler = COMPONENT_ON_NONCLICK(component);

    if (handler)
        handler(component, event, app);
}

void component_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    component_handler_t handler = COMPONENT_ON_KEYPRESS(component);

    if (handler)
        handler(component, event, app);
}
