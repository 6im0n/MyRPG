/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/

#include "types/types.h"
#include "components/components.h"
#include "types/renderer.h"
#include "lib/output.h"

static void annimation_edit(node_component_t *component)
{
    sfIntRect rect = component->features.texture_rect;
    sfIntRect rect_a = component->annimation.rect;

    if (component->annimation.index > component->annimation.max)
        component->annimation.index = 0;
    rect_a.height *= component->annimation.index;
    rect_a.top *= component->annimation.index;
    rect_a.left *= component->annimation.index;
    rect_a.width *= component->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    sfRectangleShape_setTextureRect(component->object->rectangle,
        rect);
    component->annimation.index++;
}

static void component_render_annimation(app_t *app,
node_component_t *component)
{
    sfTime time = sfClock_getElapsedTime(component->object->clock);
    float seconds = time.microseconds / 1000000.0;

    (void) app;
    if (seconds > component->annimation.speed) {
        annimation_edit(component);
        sfClock_restart(component->object->clock);
    }
}

static void component_render_dispatch(app_t *app,
node_component_t *component)
{
    switch (component->type) {
        case C_TYPES_SIGN:
        case C_TYPES_TEXT:
            sfRenderWindow_drawText(app->window,
            component->object->text, NULL);
            break;
        case C_TYPES_SPRITE:
            sfRenderWindow_drawSprite(app->window,
            component->object->sprite, NULL);
            break;
        case C_TYPES_BTN_TXT:
            render_button_effect(app, component);
            sfRenderWindow_drawText(app->window,
            component->object->text, NULL);
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
        case C_TYPES_SIGN:
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
        if (tmp->annimation.speed != 0)
            component_render_annimation(app, tmp);
        component_render_dispatch_form(app, tmp, components);
        component_render_dispatch(app, tmp);
        tmp = tmp2;
    }
}
