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

void components_setting_bouton_quit(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 200,
        850};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 772, .top = 163, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Close the game", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 30, 4}, 2);
    obj->events.onclick = &event_setting_close_windows_onclick;
    list_component_append(list, obj);
}

void components_setting_bouton_resume(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        850};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 837, .top = 164, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Resume", sfBlack, 30);
    set_component_text_pos(obj, (sfVector2f){ 30, 4}, 2);
    obj->events.onclick = &event_close_onclick;
    list_component_append(list, obj);
}

void components_resolution_1(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 0};
    sfVector2f position = {middle.x, 750 };
    sfVector2f size = {150, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_MAX);
    set_component_text(obj, "Resolution\n1920x1080", sfBlack, 22);
    set_component_text_pos(obj, (sfVector2f){ 0, -10}, 0);
    obj->events.onclick = &event_settings_resolution1_onclick;
    list_component_append(list, obj);
}

void components_resolution_2(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 0};
    sfVector2f position = {middle.x - 220, 750 };
    sfVector2f size = {150, 70};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_MAX);
    set_component_text(obj, "Resolution\n 1440x900", sfBlack, 22);
    set_component_text_pos(obj, (sfVector2f){ 0, -10}, 0);
    obj->events.onclick = &event_settings_resolution2_onclick;
    list_component_append(list, obj);
}

void components_resolution_3(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 0};
    sfVector2f position = {middle.x + 220, 750 };
    sfVector2f size = {150, 90};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 28,.left = 11,
                                        .top = 11, .width = 26}, C_SIZE_MAX);
    set_component_text(obj, " Resolution\n44340x12679", sfBlack, 22);
    set_component_text_pos(obj, (sfVector2f){ 0, -10}, 0);
    obj->events.onclick = &event_settings_resolution3_onclick;
    list_component_append(list, obj);
}
