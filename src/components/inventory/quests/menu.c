/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** menu
*/

#include "types/node.h"
#include "types/list.h"
#include "app/constants.h"
#include "components/new.h"
#include "components/get.h"
#include "parsing/buttons.h"
#include "ressources/textures.h"
#include "components/components.h"

static void inventory_quests_boards(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f middle = {W_VIDEO_MODE.width / 2, W_VIDEO_MODE.height / 2};
    sfVector2f position = {middle.x + 540, middle.y + 85 };
    sfVector2f size = {500 , 600};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_IMMORTAL };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Quests", sfBlack, 50);
    set_component_text_pos(obj, (sfVector2f){ 0, -275}, 3);
    list_component_append(list, obj);
}

void inventory_quests(app_t *app, ressources_t ressources,
list_components_t *list)
{
    inventory_quests_boards(app, ressources, list);
    parsing_buttons(app, ressources, list,
        "assets/scripts/menu/quests_inventory.txt");
}
