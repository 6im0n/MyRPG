/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** cursor
*/

#include "components/components.h"
#include "components/get.h"
#include "components/new.h"
#include "types/list.h"

void component_cursor_filter(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f size = {sfRenderWindow_getSize(app->window).x,
        sfRenderWindow_getSize(app->window).y};
    sfVector2f position = {size.x / 2, size.y / 2};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 1, .left = 0, .top = 0, .width = 1},
        C_SIZE_SMALL);
    obj->events.onhover = &event_cursor_onmove;
    list_component_append(list, obj);
}

void component_cursor(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {0, 0};
    sfVector2f size = {40, 45};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 13, .left = 338, .top = 130, .width = 12},
        C_SIZE_SMALL);
    obj->id = ID_CURSOR;
    list_component_append(list, obj);
}

void component_cursor_default(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    component_cursor_filter(app, ressources, objects, list);
    component_cursor(app, ressources, objects, list);
}
