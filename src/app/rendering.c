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
#include "components/speech.h"
#include "components/death.h"

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
        case S_DEATH:
            dispatch(app, components, components->death);
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

static void app_stages(app_t *app, main_components_t *components)
{
    if (app->state->stage == S_GAME &&
        app->element->player->life <= 0) {
        app->state->stage = S_DEATH;
        app->state->back = S_GAME;
        sfClock_restart(app->state->cycle->clock);
    }
    if ((app->state->stage == S_GAME || app->state->back == S_GAME) &&
        app->state->stage != S_DEATH && app->state->stage != S_MENU_HELP &&
        app->state->stage != S_MENU_START &&
        app->state->stage != S_MENU_LOAD_GAME)
        render_cycle_day_night(app);
    if (app->state->stage == S_SETTINGS)
        render_in_game(app, components->setting);
    if (app->state->stage == S_DEATH) {
        death_render(app);
        render_in_game(app, components->death);
    } else if (app->state->stage == S_INVENTORY) {
        render_in_game(app, components->inventory);
        app_quests_dispatch(app);
    }
}

void app_render(app_t *app, ressources_t *ressources,
main_components_t *components)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, W_COLOR);
    player_view(app);
    component_render_dispatch(app, components);
    app_player_render(app);
    app_stages(app, components);
    speech_render(app);
    sfRenderWindow_setView(app->window, app->view);
    popup_render(app);
    layer_render(app);
    app_component_render(app, components->cursor);
    sfRenderWindow_display(app->window);
}
