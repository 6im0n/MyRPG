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
#include "lib/output.h"
#include "types/node.h"

void component_cursor_filter(app_t *app,ressources_t ressources,
                                    list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f size = {500000, 500000};
    sfVector2f position = {0, 0};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 1, .left = -200, .top = 0, .width = 1},
        C_SIZE_SMALL);
    obj->events.onhover = &event_cursor_onmove;
    list_component_append(list, obj);
}

static void component_cursor(app_t *app,ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {100, 100};
    sfVector2f size = {40, 45};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 13, .left = 338, .top = 130, .width = 12},
        C_SIZE_SMALL);
    obj->id = ID_CURSOR;
    list_component_append(list, obj);
}

static void components_cursor(app_t *app,ressources_t ressources,
                                        list_components_t *list)
{
    component_cursor_filter(app, ressources, list);
    component_cursor(app, ressources, list);
}

void components_get_cursor(app_t *app, ressources_t ressources,
                                        list_components_t *list)
{
    if (!list)
        return;
    components_cursor(app, ressources, list);
}
