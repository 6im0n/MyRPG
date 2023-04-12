/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/


#include "components/components.h"
#include "types/renderer.h"
#include "lib/output.h"
#include <stdio.h>

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
            break;
        default:
            break;
    }
}

static void component_render_dispatch_form(app_t *app,
node_component_t *component)
{
    if ((component->id == ID_CURSOR && app->mouse.custom == false))
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

static void draw_item_inventory(app_t *app, node_item_t *tmp,
component_id_t slot, sfVector2f position)
{
    component_id_t select = app->element->player->inventory->select;

    if (tmp->slot == slot)
        sfRectangleShape_setPosition(tmp->shape, position);
    if (tmp->slot == select)
        sfRectangleShape_setPosition(tmp->shape, app->mouse.position);
    sfRenderWindow_drawRectangleShape(app->window, tmp->shape, NULL);
}

static void render_inventory(app_t *app, component_id_t slot,
sfVector2f position)
{
    node_item_t *tmp = app->element->player->inventory->first;
    node_item_t *tmp2 = tmp;

    if (!tmp)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        draw_item_inventory(app, tmp, slot, position);
        tmp = tmp2;
    }
}

void app_component_render(app_t *app, list_components_t *components)
{
    node_component_t *tmp = components->first;

    if (!tmp)
        return;
    while (tmp != NULL) {
        component_render_annimation(app, tmp);
        component_render_dispatch_form(app, tmp);
        component_render_dispatch(app, tmp);
        if (tmp->id >= ID_SLOT_1 && tmp->id <= ID_SLOT_8)
            render_inventory(app, tmp->id,
            sfRectangleShape_getPosition(tmp->object->rectangle));
        tmp = tmp->next;
    }
}
