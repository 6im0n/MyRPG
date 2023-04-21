/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** death
*/

#include "components/components.h"
#include <stdio.h>

void event_death_back_home(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    app->state->stage = S_MENU_START;
}
