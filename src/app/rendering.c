/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/

#include "app/app.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/mobs.h"
#include "components/view.h"
#include "components/player.h"
#include "components/components.h"

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
        case S_GAME:
            app_component_render(app, components->game);
            break;
        case S_NEW_GAME:
            app_component_render(app, components->new_game);
        default:
            break;
    }
    if (app->state->back != S_GAME)
        app_component_render(app, list);
}

static void component_render_dispatch_extend(app_t *app,
main_components_t *components)
{
    switch (app->state->stage) {
        case S_GAME:
            app_component_render(app, components->game);
            break;
        case S_NEW_GAME:
            app_component_render(app, components->new_game);
            break;
        default:
            break;
    }
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
    component_render_dispatch_extend(app, components);
}

static void player_render(app_t *app)
{
    if (app->state->stage == S_GAME || app->state->stage == S_SETTINGS ||
        app->state->stage == S_INVENTORY) {
        player_render_annimation(app);
        sfRenderWindow_drawRectangleShape(app->window,
            app->element->player->character->shape, NULL);
        mobs_render_annimation(app);
        sfRenderWindow_drawRectangleShape(app->window,
            app->layer, NULL);
    }
}

void app_render(app_t *app, ressources_t *ressources,
main_components_t *components)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, W_COLOR);
    player_view(app);
    component_render_dispatch(app, components);
    player_render(app);
    if (app->state->stage == S_SETTINGS)
        render_in_game(app, components->setting);
    if (app->state->stage == S_INVENTORY)
        render_in_game(app, components->inventory);
    app_component_render(app, components->cursor);
    sfRenderWindow_display(app->window);
}
