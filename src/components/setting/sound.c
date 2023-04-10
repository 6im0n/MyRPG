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
#include "event/setting/bouton.h"

static sfVector2f find_position_volume(app_t *app, list_components_t *list)
{
    sfVector2f position = sfRectangleShape_getPosition(
        list->last->object->rectangle);
    sfFloatRect rect = list->last->features.rendered_rect;
    int pourcentage = (rect.width / 100) * app->state->sound->volume_music;

    position.x = rect.left + pourcentage;
    return position;
}

void components_menu_setting_selector_volume_music(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        370};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {250 / 1.3, 15 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 4, .left = 277, .top = 166, .width = 38},
        C_SIZE_TOP_MEDIUM);
    obj->id = ID_MUSIC_CURSOR;
    set_component_text(obj, "Music Volume", sfBlack, 35);
    set_component_text_pos(obj, (sfVector2f){ 148, -14}, 2);
    list_component_append(list, obj);
}

void components_menu_setting_selector_volume_music_cursor(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = find_position_volume(app, list);
    sfVector2f size = {30 / 1.3, 50 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 21, .left = 65,
                            .top = 197, .width = 14}, C_SIZE_TOP_MEDIUM);
    obj->events.onmove = &event_settings_selector_volume_onclick;
    obj->events.onnonclick = &event_settings_selector_volume_onnonclick;
    obj->events.ondisabled = &event_settings_selector_volume_ondisabled;
    list_component_append(list, obj);
}

void components_menu_setting_selector_volume_sound(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        420};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {250 / 1.3, 15 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 4, .left = 277, .top = 166, .width = 38},
        C_SIZE_TOP_MEDIUM);
    obj->id = ID_SOUND_CURSOR;
    set_component_text(obj, "Sound Volume", sfBlack, 35);
    set_component_text_pos(obj, (sfVector2f){ 148, -14}, 2);
    list_component_append(list, obj);
}

void components_menu_setting_selector_volume_sound_cursor(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = find_position_volume(app, list);
    sfVector2f size = {30 / 1.3, 50 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 21, .left = 65,
                            .top = 197, .width = 14}, C_SIZE_TOP_MEDIUM);
    obj->events.onmove = &event_settings_selector_volume_onclick;
    obj->events.onnonclick = &event_settings_selector_volume_onnonclick;
    obj->events.ondisabled = &event_settings_selector_volume_ondisabled;
    list_component_append(list, obj);
}
