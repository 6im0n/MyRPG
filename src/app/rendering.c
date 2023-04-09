/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/


#include "app/app.h"
#include "app/ressources.h"
#include "app/constants.h"
#include "components/components.h"
#include <SFML/Graphics.h>
#include <stdio.h>
#include "lib/output.h"
#include "components/player.h"
#include "components/mobs.h"

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
        default:
            break;
    }
    app_component_render(app, list);
}

static void component_render_dispatch_extend(app_t *app,
main_components_t *components)
{
    switch (app->state->stage) {
        case S_GAME:
            app_component_render(app, components->game);
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
    if (app->state->stage == S_GAME){
        player_render_annimation(app);
        sfRenderWindow_drawRectangleShape(app->window,
            app->element->player->character->shape, NULL);
    }
}

static void mobs_render(app_t *app)
{
    if (app->state->stage == S_GAME){
        mobs_render_annimation(app);
        sfRenderWindow_drawRectangleShape(app->window,
            app->element->mobs->character->shape, NULL);
    }
}

void app_render(app_t *app, ressources_t *ressources,
main_components_t *components)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, W_COLOR);
    sfRenderWindow_setView(app->window, app->view);
    component_render_dispatch(app, components);
    player_render(app);
    mobs_render(app);
    app_component_render(app, components->cursor);
    sfRenderWindow_display(app->window);
}
