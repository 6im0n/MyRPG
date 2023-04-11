/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** dialog
*/

#include <stdio.h>
#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"
#include "event/start_menu/bouton.h"

void dialog_main_quests_next_to(node_component_t *component,
event_t *event, app_t *app)
{
    (void) app;
    (void) event;
    (void) component;
    sfVector2f scale =
        sfRectangleShape_getScale(component->prev->object->rectangle);

    if (scale.x > 0) {
        scale.x -= 0.05;
        scale.y -= 0.05;
    }
    sfRectangleShape_setScale(component->prev->object->rectangle, scale);
}

void dialog_main_quests_disabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) app;
    (void) event;
    (void) component;
    sfVector2f scale =
        sfRectangleShape_getScale(component->prev->object->rectangle);

    if (scale.x < 1) {
        scale.x += 0.05;
        scale.y += 0.05;
    }
    sfRectangleShape_setScale(component->prev->object->rectangle, scale);
}

void dialog_main_quests_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    if (!ST_IS_NEAR(component))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyI))
        printf("OPEN DIALOG\n");
}
