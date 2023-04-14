/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "app/constants.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"
#include "event/setting/bouton.h"
#include "event/start_menu/bouton.h"
#include "event/global.h"
#include "types/node.h"

static void menu_board(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f middle = {W_VIDEO_MODE.width / 2,
        W_VIDEO_MODE.height / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {middle.x * 1 , middle.y * 1.6};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 11, .top = 12, .width = 106},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

void components_setting_bouton_mouse(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2 - 200,
        570};
    sfVector2f size = {100 / 1.3, 60 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 18, .left = 434, .top = 103, .width = 28},
        C_SIZE_TOP_MEDIUM);
    set_component_text(obj, "Custom Mouse", sfBlack, 35);
    set_component_text_pos(obj, (sfVector2f){ 148, -14}, 2);
    obj->id = ID_SELECTOR;
    obj->features.select = true;
    obj->events.onclick = &event_settings_mouse_onclick;
    list_component_append(list, obj);
}

static void components_setting_bouton_help(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f position = {W_VIDEO_MODE.width / 2 ,
        835};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 24, .left = 709,
        .top = 164, .width = 22}, C_SIZE_SMALL);
    set_component_text(obj, "Help", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_open_help_onclick;
    list_component_append(list, obj);
}

static void setting_bouton_screen(app_t *app,ressources_t ressources,
list_components_t *list)
{
    components_setting_bouton_fullscreen(app, ressources, list);
    components_menu_setting_selector_framelimit(app,
        ressources, list);
    components_menu_setting_selector_framelimit_cursor(app,
        ressources, list);
    components_setting_bouton_mouse(app, ressources, list);
    components_resolution_1(app, ressources, list);
}

void components_setting(app_t *app,ressources_t ressources,
list_components_t *list)
{
    menu_board(app, ressources, list);
    components_menu_setting_selector_sound(app, ressources, list);
    components_menu_setting_selector_volume_music(app,
        ressources, list);
    components_menu_setting_selector_volume_music_cursor(app,
        ressources, list);
    components_menu_setting_selector_volume_sound(app,
        ressources, list);
    components_menu_setting_selector_volume_sound_cursor(app,
        ressources, list);
    components_setting_bouton_quit(app, ressources, list);
    components_setting_bouton_resume(app, ressources, list);
    components_setting_bouton_help(app, ressources, list);
    setting_bouton_screen(app, ressources, list);
    components_resolution_1(app, ressources, list);
    components_resolution_2(app, ressources, list);
    components_resolution_3(app, ressources, list);
}
