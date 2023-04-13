/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** render_background
*/

#include "components/components.h"
#include "types/renderer.h"

void component_render_background(app_t *app,
node_component_t *component)
{
    if (component->type == C_TYPES_BACKGROUND) {
        sfRenderWindow_setView(app->window, app->background);
        sfRenderWindow_drawRectangleShape(app->window,
        component->object->rectangle, NULL);
        sfRenderWindow_setView(app->window, app->view);
    }
}
