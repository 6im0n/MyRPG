/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/

#include "types/types.h"
#include "components/components.h"
#include "types/renderer.h"

static void component_render_dispatch(app_t *app,
node_component_t *component)
{
    switch (component->type) {
        case C_TYPES_TEXT:
            sfRenderWindow_drawText(app->window,
            component->object->text, NULL);
            break;
        case C_TYPES_SPRITE:
            sfRenderWindow_drawSprite(app->window,
            component->object->sprite, NULL);
            break;
        default:
            break;
    }
}

static void component_render_dispatch_form(app_t *app,
node_component_t *component, list_components_t *components)
{
    if ((component->id == ID_CURSOR && components->id != app->state->stage) ||
        (component->id == ID_CURSOR && app->mouse.custom == false))
        return;
    switch (component->type) {
        case C_TYPES_RECTANGLE:
            sfRenderWindow_drawRectangleShape(app->window,
            component->object->rectangle, NULL);
            break;
        case C_TYPES_BUTTON:
            render_button_effect(app, component);
            break;
        case C_TYPES_CIRCLE:
            sfRenderWindow_drawCircleShape(app->window,
            component->object->circle, NULL);
            break;
        default:
            break;
    }
}

void app_component_render(app_t *app, list_components_t *components)
{
    node_component_t *tmp = components->first;
    node_component_t *tmp2 = tmp;

    if (!tmp)
        return;
    (void) app;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        component_render_dispatch_form(app, tmp, components);
        component_render_dispatch(app, tmp);
        tmp = tmp2;
    }
}
