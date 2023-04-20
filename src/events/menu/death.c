/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** death
*/

#include "components/components.h"
#include <stdio.h>

void event_timer_onhover(node_component_t *component,
event_t *event, app_t *app)
{
    sfColor c = sfRectangleShape_getFillColor(component->object->rectangle);

    (void) event;
    (void) app;
    if (app->state->stage != app->state->back) {
        c.a = 0;
        app->state->back = app->state->stage;
    }
    if (c.a < 200) {
        c.a++;
        sfRectangleShape_setFillColor(component->object->rectangle, c);
    }
}

void event_death_back_home(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    app->state->stage = S_MENU_START;
}
