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
#include "components/get.h"
#include "event/setting/bouton.h"
#include "event/start_menu/bouton.h"
#include "event/global.h"

static void menu_board(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {middle.x * 1 , middle.y * 1.6};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_ARIAL };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 11, .top = 12, .width = 106},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

void components_setting_bouton_mouse(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        640};
    sfVector2f size = {100, 60};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 18, .left = 434, .top = 103, .width = 28},
        C_SIZE_TOP_MEDIUM);
    set_component_text(obj, "Custom Mouse", sfBlack, 50);
    set_component_text_pos(obj, (sfVector2f){ 148, -22}, 2);
    obj->id = ID_SELECTOR;
    obj->features.select = true;
    obj->events.onclick = &event_settings_mouse_onclick;
    list_component_append(list, obj);
}

static void components_setting_bouton_help(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 ,
        835};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size, (sfIntRect){.height = 24, .left = 709,
        .top = 164, .width = 22}, C_SIZE_SMALL);
    set_component_text(obj, "Help", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_open_help_onclick;
    list_component_append(list, obj);
}

static void setting_bouton_screen(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    components_setting_bouton_fullscreen(app, ressources, objects, list);
    components_menu_setting_selector_framelimit(app,
        ressources, objects, list);
    components_menu_setting_selector_framelimit_cursor(app,
        ressources, objects, list);
    components_menu_setting_selector_framerate_title(app,
        ressources, objects, list);
    components_setting_bouton_mouse(app, ressources, objects, list);
    components_resolution_1(app, ressources, objects, list);
}

list_components_t *components_setting(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    menu_board(app, ressources, objects, list);
    components_menu_setting_selector_sound(app, ressources, objects, list);
    components_menu_setting_selector_volume(app, ressources, objects, list);
    components_menu_setting_selector_volume_cursor(app,
        ressources, objects, list);
    components_menu_setting_selector_volume_title(app,
        ressources, objects, list);
    components_setting_bouton_quit(app, ressources, objects, list);
    components_setting_bouton_resume(app, ressources, objects, list);
    components_setting_bouton_help(app, ressources, objects, list);
    setting_bouton_screen(app, ressources, objects, list);
    components_resolution_1(app, ressources, objects, list);
    components_resolution_2(app, ressources, objects, list);
    components_resolution_3(app, ressources, objects, list);
    component_cursor_default(app, ressources, objects, list);
    return list;
}
