/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>

#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"
#include "app/constants.h"
#include "types/node.h"

static void menu_board(app_t *app, ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f middle = {W_VIDEO_MODE.width / 2, W_VIDEO_MODE.height / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {middle.x * 1.8 , middle.y * 1.6};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

static void menu_title(app_t *app, ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = node_component_init();
    float middle = W_VIDEO_MODE.width / 2;
    sfVector2f position = { middle, 180 };
    sfVector2f size = {40, 40};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_TEXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Inventory", sfBlack, 150);
    list_component_append(list, obj);
}

static void annimation_env(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    float middle = W_VIDEO_MODE.width / 2;
    sfVector2f position = { middle - 50, 600 };
    sfVector2f size = {700, 620};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_NATURE, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 65, .left = 0, .top = 0, .width = 63},
        C_SIZE_MAX);
    new_component_annimation(obj, (sfIntRect){.height = 0, .left = 64,
        .top = 0, .width = 0}, 0, 7);
    obj->annimation.speed = 0.1;
    list_component_append(list, obj);
}

static void annimation_player(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    float middle = W_VIDEO_MODE.width / 2;
    sfVector2f position = { middle, 600 };
    sfVector2f size = {200, 300};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_PLAYER_1, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 16 + 48, .top = 68, .width = 17},
        C_SIZE_MAX);
    new_component_annimation(obj, (sfIntRect){.height = 0, .left = 48,
        .top = 0, .width = 0}, 0, 4);
    obj->annimation.speed = 0.3;
    list_component_append(list, obj);
}

void components_inventory(app_t *app,ressources_t ressources,
                            list_components_t *list)
{
    menu_board(app, ressources, list);
    menu_title(app, ressources, list);
    annimation_env(app, ressources, list);
    annimation_player(app, ressources, list);
    inventory_object(app, ressources, list);
    inventory_quests(app, ressources, list);
}
