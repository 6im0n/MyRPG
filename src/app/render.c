/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** render
*/

#include "app/app.h"
#include "components/components.h"

void render_in_game(app_t *app, list_components_t *list)
{
    if (app->state->back == S_GAME)
        sfRenderWindow_setView(app->window, app->view);
    app_component_render(app, list);
}
