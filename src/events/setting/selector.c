/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include <stdbool.h>

void event_settings_selector_mute_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (ST_IS_PRESSED(component))
        app->state->sound->mute = !app->state->sound->mute;
    component->features.select = app->state->sound->mute;
}
