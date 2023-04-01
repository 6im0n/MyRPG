/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/

#include "types/types.h"
#include "app/app.h"
#include "app/ressources.h"
#include "app/constants.h"
#include "components/components.h"
#include <SFML/Graphics.h>
#include <stdio.h>

static void dispatch(app_t *app,
main_components_t *components, list_components_t *list)
{
    switch (app->state->back) {
        case S_MENU_START:
            app_component_render(app, components->start_menu);
            break;
        case S_MENU_HELP:
            app_component_render(app, components->help_menu);
            break;
        default:
            break;
    }
    app_component_render(app, list);
}

static void component_render_dispatch(app_t *app,
main_components_t *components)
{
    switch (app->state->stage) {
    case S_MENU_START:
        app_component_render(app, components->start_menu);
        break;
    case S_MENU_HELP:
        app_component_render(app, components->help_menu);
        break;
    case S_INVENTORY:
        dispatch(app, components, components->inventory);
        break;
    case S_SETTINGS:
        dispatch(app, components, components->setting);
        break;
    default:
        break;
    }
}

void app_render(app_t *app, ressources_t *ressources,
main_components_t *components)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, W_COLOR);
    component_render_dispatch(app, components);
    sfRenderWindow_display(app->window);
}