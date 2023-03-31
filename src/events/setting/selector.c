/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include <stdbool.h>
#include "lib/tools.h"
#include "lib/str.h"

void event_settings_selector_mute_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (ST_IS_PRESSED(component))
        app->state->sound->mute = !app->state->sound->mute;
    component->features.select = app->state->sound->mute;
}

static void set_volume_string(node_component_t *component, int volume)
{
    node_component_t *next = component->next;
    char *string = malloc(my_nbrlen(volume) + 3);

    if (!next || next->id != ID_VOLUME_CURSOR)
        return;
    my_strcpy(string, my_char(volume));
    my_strcat(string, " %\0");
    sfText_setString(next->object->text, string);
}

void event_settings_selector_volume_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    sfFloatRect prev = component->prev->features.rendered_rect;
    sfVector2f pos = sfRectangleShape_getPosition(
        component->object->rectangle);
    sfVector2f max = {
        component->prev->features.rendered_rect.left,
        component->prev->features.rendered_rect.left +
        component->prev->features.rendered_rect.width
    };
    int volume = 0;

    pos.x = app->mouse.position.x;
    if (pos.x >= max.x && pos.x <= max.y) {
        sfRectangleShape_setPosition(component->object->rectangle, pos);
        volume = ((pos.x - prev.left) / prev.width) * 100;
        app->state->sound->volume = volume;
        set_volume_string(component, volume);
    }
}

void event_settings_selector_volume_onnonclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    sfFloatRect rect =
        sfRectangleShape_getGlobalBounds(component->object->rectangle);

    component->features.rendered_rect = rect;
}
