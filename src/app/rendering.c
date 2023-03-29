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

static void component_render_dispatch(app_t *app,
main_components_t *components)
{
    if (app->state->stage == S_START_MENU)
        app_component_render(app, components->start_menu);
}

void app_render(app_t *app, ressources_t *ressources,
main_components_t *components)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, W_COLOR);
    component_render_dispatch(app, components);
    sfRenderWindow_display(app->window);
}
