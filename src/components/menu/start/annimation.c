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
#include "components/get.h"
#include "event/annimation.h"

static void annimation_boat(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = { 560, 650 };
    sfVector2f size = {300, 300};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_SHIP, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 65, .left = 0, .top = 0, .width = 63},
        C_SIZE_MAX);
    new_component_annimation(obj, (sfIntRect){.height = 0, .left = 64,
        .top = 0, .width = 0}, 10, 15);
    obj->annimation.speed = 0.15;
    obj->events.onhover = &event_active_annimation;
    obj->events.ondisabled = &event_pause_annimation;
    list_component_append(list, obj);
}

static void annimation_env(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = { 1320, 634 };
    sfVector2f size = {500, 430};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_NATURE, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 65, .left = 0, .top = 0, .width = 63},
        C_SIZE_MAX);
    new_component_annimation(obj, (sfIntRect){.height = 0, .left = 64,
        .top = 0, .width = 0}, 0, 7);
    obj->annimation.speed = 0.1;
    list_component_append(list, obj);
}

static void annimation_chalice(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = { 1320, 634 };
    sfVector2f size = {200, 230};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_CHALICE, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 65, .left = 0, .top = 0, .width = 63},
        C_SIZE_MAX);
    new_component_annimation(obj, (sfIntRect){.height = 0, .left = 64,
        .top = 0, .width = 0}, 0, 7);
    obj->annimation.speed = 0.1;
    obj->events.onhover = &event_active_annimation;
    obj->events.ondisabled = &event_disabled_annimation;
    list_component_append(list, obj);
}

void components_menu_start_annimation(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    annimation_boat(app, ressources, objects, list);
    annimation_chalice(app, ressources, objects, list);
    annimation_env(app, ressources, objects, list);
}
