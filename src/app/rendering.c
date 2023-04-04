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
#include "lib/output.h"

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
        case S_MENU_LOAD_GAME:
            app_component_render(app, components->load_game);
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
        case S_MENU_LOAD_GAME:
            app_component_render(app, components->load_game);
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
    app_component_render(app, components->cursor);
}

static void render_inventory(app_t *app)
{
    node_item_t *tmp = app->element->player->inventory->first;
    node_item_t *tmp2 = tmp;

    if (!tmp)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfRenderWindow_drawRectangleShape(app->window, tmp->shape, NULL);
        tmp = tmp2;
    }
}

static void player_render(app_t *app)
{
    sfRenderWindow_drawRectangleShape(app->window,
        app->element->player->character->shape, NULL);
    render_inventory(app);
}

void app_render(app_t *app, ressources_t *ressources,
main_components_t *components)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, W_COLOR);
    component_render_dispatch(app, components);
    player_render(app);
    sfRenderWindow_display(app->window);
}
