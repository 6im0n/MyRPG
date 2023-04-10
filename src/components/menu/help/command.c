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
#include "event/start_menu/bouton.h"
#include "event/setting/bouton.h"

static void components_help_bouton_setting(app_t *app, ressources_t ressources,
                                            list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 500,
        225};
    sfVector2f size = {120, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "Escape", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

void components_help_command_setting(app_t *app, ressources_t ressources,
                                    list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 500,
        200};
    sfVector2f size = {300, 125};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 122, .left = 139,
                                        .top = 12, .width = 106}, C_SIZE_BIG);
    set_component_text(obj, "Open Settings", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -40}, 0);
    list_component_append(list, obj);
    components_help_bouton_setting(app, ressources, list);
}

static void components_help_bouton_inventory(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 500,
        225};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "E", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

void components_help_command_inventory(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 500,
        200};
    sfVector2f size = {300, 125};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 122, .left = 139,
                                        .top = 12, .width = 106}, C_SIZE_BIG);
    set_component_text(obj, "Open Inventory", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -40}, 0);
    list_component_append(list, obj);
    components_help_bouton_inventory(app, ressources, list);
}
