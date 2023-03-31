/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/types.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "event/start_menu/bouton.h"
#include "event/inventory/bouton.h"
#include "components/get.h"

static void object_line_top(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f pos = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {pos.x - (size.x / 2),
        (pos.y - (size.y / 2)), size.x, size.y};
    component_styles style = { TX_INVENTORY_COMPO, SD_NONE, FT_ARIAL };

    pos.y = middle.y - 150;
    pos.x = middle.x - 150;
    for (int i = 0; i < 2; i++) {
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, objects, pos);
        new_component_size(obj, size, (sfIntRect){0, 0, 0, 0}, C_SIZE_SMALL);
        obj->events.onclick = &event_selector_onpress;
        list_component_append(list, obj);
        pos.x = middle.x - 200;
        pos.y = middle.y;
    }
}

static void object_line_bottom(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f pos = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {pos.x - (size.x / 2),
        (pos.y - (size.y / 2)), size.x, size.y};
    component_styles style = { TX_INVENTORY_COMPO, SD_NONE, FT_ARIAL };

    pos.x = middle.x + 150;
    pos.y = middle.y - 150;
    for (int i = 0; i < 2; i++) {
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, objects, pos);
        new_component_size(obj, size, (sfIntRect){0, 0, 0, 0}, C_SIZE_SMALL);
        obj->events.onclick = &event_selector_onpress;
        list_component_append(list, obj);
        pos.y = middle.y - 200;
        pos.x = middle.x;
    }
}

static void object_diagonal_left(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f pos = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {pos.x - (size.x / 2),
        (pos.y - (size.y / 2)), size.x, size.y};
    component_styles style = { TX_INVENTORY_COMPO, SD_NONE, FT_ARIAL };

    pos.y = middle.y + 150;
    pos.x = middle.x - 150;
    for (int i = 0; i < 2; i++) {
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, objects, pos);
        new_component_size(obj, size, (sfIntRect){0, 0, 0, 0}, C_SIZE_SMALL);
        obj->events.onclick = &event_selector_onpress;
        list_component_append(list, obj);
        pos.y = middle.y + 200;
        pos.x = middle.x;
    }
}

static void object_diagonal_right(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f pos = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {pos.x - (size.x / 2),
        (pos.y - (size.y / 2)), size.x, size.y};
    component_styles style = { TX_INVENTORY_COMPO, SD_NONE, FT_ARIAL };

    pos.y = middle.y + 150;
    pos.x = middle.x + 150;
    for (int i = 0; i < 2; i++) {
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, objects, pos);
        new_component_size(obj, size, (sfIntRect){0, 0, 0, 0}, C_SIZE_SMALL);
        obj->events.onclick = &event_selector_onpress;
        list_component_append(list, obj);
        pos.x = middle.x + 200;
        pos.y = middle.y;
    }
}

void inventory_object(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    object_line_top(app, ressources, objects, list);
    object_diagonal_left(app, ressources, objects, list);
    object_diagonal_right(app, ressources, objects, list);
    object_line_bottom(app, ressources, objects, list);
    inventory_object_add_id(list->last);
    inventory_object_select(app, ressources, objects, list);
}
