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
#include "event/setting/bouton.h"

static void components_help_bouton_setting(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        525};
    sfVector2f size = {120, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "Escape", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    obj->events.onclick = &event_settings_open_onclick;
    list_component_append(list, obj);
}

void components_help_command_setting(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        500};
    sfVector2f size = {300, 125};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 122, .left = 139,
                                        .top = 12, .width = 106}, C_SIZE_BIG);
    set_component_text(obj, "Open Settings", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -40}, 0);
    list_component_append(list, obj);
    components_help_bouton_setting(app, ressources, objects, list);
}

static void components_help_bouton_inventory(app_t *app,
ressources_t ressources, renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 200,
        525};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "E", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    obj->events.onclick = &event_bouton_help_onclick;
    list_component_append(list, obj);
}

void components_help_command_inventory(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 200,
        500};
    sfVector2f size = {300, 125};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 122, .left = 139,
                                        .top = 12, .width = 106}, C_SIZE_BIG);
    set_component_text(obj, "Open Inventory", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -40}, 0);
    list_component_append(list, obj);
    components_help_bouton_inventory(app, ressources, objects, list);
}
