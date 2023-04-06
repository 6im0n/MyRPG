/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/


#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"
#include "event/global.h"
#include "lib/output.h"
#include "components/player.h"

void inventory_equip_item(node_component_t *component,
event_t *event, app_t *app)
{
    component_id_t selector = app->element->player->inventory->selector;

    (void) event;
    (void) component;
    swap_item_player(app->element->player->inventory, selector, ID_SLOT_1);
    component->state = ST_SET_CLICKED(component, false);
}

void inventory_delete_item(node_component_t *component,
event_t *event, app_t *app)
{
    component_id_t selector = app->element->player->inventory->selector;

    (void) event;
    (void) component;
    list_item_delete(app->element->player->inventory, selector);
    component->state = ST_SET_CLICKED(component, false);
}

static void inventory_drop_done(node_component_t *component,
app_t *app)
{
    component_id_t last = app->element->player->inventory->last_select;
    component_id_t select = app->element->player->inventory->select;

    if (select != ID_UNDEFINED)
        last = component->id;
    component->state = ST_SET_CLICKED(component, false);
    component->state = ST_SET_PRESSED(component, false);
    component->state = ST_SET_HOVER(component, false);
    if (last != ID_UNDEFINED && select != ID_UNDEFINED && last != select)
        swap_item_player(app->element->player->inventory, last, select);
}

static void move_bouton(node_component_t *component,
sfVector2f pos, char *string)
{
    node_component_t *delete = component->next->next;
    node_component_t *equip = component->next->next->next;
    sfVector2f deletepos = {pos.x - 50, pos.y + 60};
    sfVector2f equippos = {pos.x + 50, pos.y + 60};
    sfVector2f textpos = {pos.x, pos.y - 80};
    sfVector2f pos_text = {pos.x, pos.y + 50};

    sfText_setPosition(component->next->object->text, pos_text);
    sfText_setString(component->next->object->text, string);
    sfRectangleShape_setPosition(component->object->rectangle, pos);
    sfRectangleShape_setPosition(delete->object->rectangle, deletepos);
    sfText_setPosition(delete->object->text, textpos);
    delete->features.rendered_rect =
        sfRectangleShape_getGlobalBounds(delete->object->rectangle);
    sfRectangleShape_setPosition(equip->object->rectangle, equippos);
    sfText_setPosition(equip->object->text, textpos);
    equip->features.rendered_rect =
        sfRectangleShape_getGlobalBounds(equip->object->rectangle);
}

void event_selector_onpress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    sfVector2f pos = sfRectangleShape_getPosition(
        component->object->rectangle);
    char *string = malloc(7);

    inventory_drop_done(component, app);
    if (component->id > app->element->player->inventory->last->slot)
        return;
    app->element->player->inventory->selector = component->id;
    my_strcpy(string, "Slot  ");
    string[5] = component->id + '0';
    event_play_music(component, app);
    while (component) {
        if (component->id == ID_MAIN_INV_SELECTOR)
            move_bouton(component, pos, string);
        component = component->next;
    }
    free(string);
}
