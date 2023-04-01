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

void event_settings_fullscreen_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    (void) app;
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    if (component->features.select == false) {
        sfRenderWindow_destroy(app->window);
        app->window = sfRenderWindow_create(mode, W_TITLE,
            sfFullscreen, NULL);
        component->features.select = true;
    } else {
        sfRenderWindow_destroy(app->window);
        app->window = sfRenderWindow_create(mode, W_TITLE,
            sfResize | sfClose, NULL);
        component->features.select = false;
    }
    sfRenderWindow_setFramerateLimit(app->window, app->state->framerate);
    sfRenderWindow_clear(app->window, W_COLOR);
    if (app->mouse.custom == true)
        sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    component->state = ST_SET_CLICKED(component, false);
}

void event_settings_mouse_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    if (ST_IS_CLICKED(component))
        app->mouse.custom = !app->mouse.custom;
    component->features.select = app->mouse.custom;
    component->state = ST_SET_CLICKED(component, false);
    if (app->mouse.custom == true)
        sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
    else
        sfRenderWindow_setMouseCursorVisible(app->window, sfTrue);
    component->state = ST_SET_CLICKED(component, false);
}
