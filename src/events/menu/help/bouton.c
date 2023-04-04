/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/


#include "components/components.h"
#include "lib/output.h"
#include "event/global.h"

void event_help_bouton_home_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    event_play_music(component, app);
    app->state->stage = S_MENU_START;
}

void event_bouton_help_onhover(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;

    sfText_setColor(component->object->text, sfBlack);
}

void event_bouton_help_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    sfText_setColor(component->object->text, sfTransparent);
}
