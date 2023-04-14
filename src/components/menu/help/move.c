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
#include "app/constants.h"
#include "types/node.h"

static void components_help_bouton_up(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2, 160};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "Z", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

static void components_help_bouton_left(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2 - 60,
        240};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "Q", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

static void components_help_bouton_down(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2,
        240};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "S", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

static void components_help_bouton_right(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2 + 60,
        240};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_BIG);
    set_component_text(obj, "D", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

void components_help_bouton_move(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2,
        200};
    sfVector2f size = {350, 200};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,(sfIntRect){.height = 122, .left = 139,
                                        .top = 12, .width = 106}, C_SIZE_BIG);
    set_component_text(obj, "Player movement", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
    components_help_bouton_up(app, ressources, list);
    components_help_bouton_left(app, ressources, list);
    components_help_bouton_down(app, ressources, list);
    components_help_bouton_right(app, ressources, list);
}
