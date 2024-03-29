/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "components/components.h"
#include "components/misc/events.h"

static void catch(node_component_t *component, event_t *event, app_t *app)
{
    if (ST_IS_CLICKED(component))
        component_onclick(component, event, app);
    if (ST_IS_HOVER(component))
        component_onhover(component, event, app);
    if (ST_IS_MOVED(component))
        component_onmove(component, event, app);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !ST_IS_CLICKED(component))
        component_onnonclick(component, event, app);
    if (event->original.type == sfEvtKeyPressed)
        component_onkeypress(component, event, app);
    if (event->original.type == sfEvtKeyReleased)
        component_onkeyrelease(component, event, app);
    if (!ST_IS_HOVER(component))
        component_ondisabled(component, event, app);
    if (ST_IS_NEAR(component))
        component_next_to(component, event, app);
}

static void component_dispatch_event(list_components_t *component,
event_t *event, app_t *app)
{
    node_component_t *tmp = component->first;
    node_component_t *tmp2 = tmp;

    if (!component)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        component_set_state_from_event(tmp, event, app);
        catch(tmp, event, app);
        tmp = tmp2;
    }
}

void components_dispatch_event(list_components_t *components,
event_t *event, app_t *app)
{
    if (!components)
        return;
    component_dispatch_event(components, event, app);
}
