/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"

void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) app;
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        app->state->back = app->state->stage;
        app->state->stage = S_INVENTORY;
    }
}

void event_key_inventory_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) app;
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        app->state->stage = app->state->back;
}

void event_selector_onpress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    sfVector2f pos = sfRectangleShape_getPosition(
        component->object->rectangle);
    sfVector2f pos_text = {pos.x, pos.y + 50};
    char *string = malloc(7);

    my_strcpy(string, "Slot  ");
    string[5] = component->id + '0';
    while (component) {
        if (component->id == ID_MAIN_INV_SELECTOR) {
            sfRectangleShape_setPosition(component->object->rectangle, pos);
            sfText_setPosition(component->next->object->text, pos_text);
            sfText_setString(component->next->object->text, string);
        }
        component = component->next;
    }
    free(string);
}
