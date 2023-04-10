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
#include "event/inventory/bouton.h"
#include "components/get.h"
#include "lib/output.h"
#include <math.h>

static sfVector2f angle_set_rotate(sfVector2f point,
sfVector2f origin, float angle)
{
    int pointx = 0;
    int pointy = 0;
    int x = 0;
    int y = 0;

    angle *= M_PI / 180;
    pointx = point.x - origin.x;
    pointy = point.y - origin.y;
    x = pointx * cos(angle) + pointy * sin(angle) + origin.x;
    y = - pointx * sin(angle) + pointy * cos(angle) + origin.y;
    return ((sfVector2f){x, y});
}

static void set_event_item_inventory(node_component_t *obj)
{
    obj->events.onclick = &event_selector_onpress;
    obj->events.onhover = &item_player_hover;
}

static void object_item_inventory(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = NULL;
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f pos = {middle.x, middle.y};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {pos.x - (size.x / 2),
        (pos.y - (size.y / 2)), size.x, size.y};
    component_styles style = { TX_INVENTORY_COMPO, SD_GRAB, FT_DROID };
    float angle = 360 / 8;
    sfVector2f pos_angle = {pos.x + 230, pos.y};

    for (int i = 0; i <= 8; i++) {
        pos_angle = angle_set_rotate((sfVector2f) {pos.x + 220, pos.y},
        pos, 90 + (angle * i));
        obj = malloc(sizeof(node_component_t));
        new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
        new_component_type(ressources, obj, pos_angle);
        new_component_size(obj, size, (sfIntRect){0, 0, 0, 0}, C_SIZE_SMALL);
        set_event_item_inventory(obj);
        list_component_append(list, obj);
    }
}

static void main_selector(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2, 600};
    sfVector2f position = {middle.x, 380};
    sfVector2f size = {90, 90};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_INV_SELECTOR2, SD_NONE, FT_DROID };

    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
        C_SIZE_SMALL);
    set_component_text(obj, "Right Hand", sfBlack, 20);
    set_component_text_pos(obj, (sfVector2f){ 0, -85}, 0);
    list_component_append(list, obj);
}

void inventory_object(app_t *app, ressources_t ressources,
list_components_t *list)
{
    object_item_inventory(app, ressources, list);
    inventory_object_add_id(list->last);
    inventory_object_select(app, ressources, list);
    main_selector(app, ressources, list);
}
