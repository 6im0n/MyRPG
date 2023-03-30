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

static void object_line_top(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 500};
    sfVector2f position = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_INVENTORY_COMPO, SD_NONE, FT_ARIAL };

    (void) app;
    position.x = middle.x - 100;
    for (int i = 0; i < 2; i++) {
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, objects, position);
        new_component_size(obj, size,
            (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
            C_SIZE_SMALL);
        list_component_append(list, obj);
        position.x = middle.x + 100;
    }
}

static void object_line_bottom(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 500};
    sfVector2f position = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_INVENTORY_COMPO, SD_NONE, FT_ARIAL };

    (void) app;
    position.y = middle.y - 100;
    for (int i = 0; i < 2; i++) {
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, objects, position);
        new_component_size(obj, size,
            (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
            C_SIZE_SMALL);
        list_component_append(list, obj);
        position.y = middle.y + 100;
    }
}

static void object_background(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1350,
        700};
    sfVector2f size = {600, 300};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 26, .left = 107, .top = 155, .width = 26},
        C_SIZE_SMALL);
    (void) list;
    // list_component_append(list, obj);
}

void inventory_object(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    object_background(app, ressources, objects, list);
    object_line_top(app, ressources, objects, list);
    object_line_bottom(app, ressources, objects, list);
}
