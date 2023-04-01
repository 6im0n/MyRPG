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
    sfRenderWindow_setMouseCursorVisible(app->window, sfFalse);
}
