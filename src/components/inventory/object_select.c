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

static void main_selector(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f position = {middle.x, 400};
    sfVector2f size = {100, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 25, .left = 148, .top = 148, .width = 24},
        C_SIZE_SMALL);
    list_component_append(list, obj);
}

static void main_title(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f position = {middle.x, 450};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    new_component_set(obj, rect, C_TYPES_TEXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Main", sfBlack, 20);
    list_component_append(list, obj);
}

static void secondary_selector(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f position = {middle.x, 800};
    sfVector2f size = {90, 90};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 25, .left = 180, .top = 148, .width = 24},
        C_SIZE_SMALL);
    list_component_append(list, obj);
}

static void secondary_title(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f position = {middle.x, 735};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    new_component_set(obj, rect, C_TYPES_TEXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Secondary", sfBlack, 20);
    list_component_append(list, obj);
}

void inventory_object_select(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    main_selector(app, ressources, objects, list);
    main_title(app, ressources, objects, list);
    secondary_selector(app, ressources, objects, list);
    secondary_title(app, ressources, objects, list);
}
