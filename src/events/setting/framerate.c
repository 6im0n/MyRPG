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

static void set_framerate_string(node_component_t *component, int volume)
{
    node_component_t *next = component->next;
    char *string = malloc(my_nbrlen(volume) + 5);

    if (!next || next->id != ID_VOLUME_CURSOR)
        return;
    my_strcpy(string, my_char(volume));
    my_strcat(string, " fps\0");
    sfText_setString(next->object->text, string);
}

void event_settings_selector_framerate_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    sfText_setString(component->next->object->text, "Framerate");
}

void event_settings_selector_framerate_onclick(node_component_t *component,
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
    int framelimit = 1;

    pos.x = app->mouse.position.x;
    if (pos.x >= max.x && pos.x <= max.y) {
        sfRectangleShape_setPosition(component->object->rectangle, pos);
        framelimit = ((pos.x - prev.left) / prev.width) * 265;
        app->state->framerate = framelimit;
        set_framerate_string(component, framelimit);
    }
}

void event_settings_selector_framerate_onnonclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    sfFloatRect rect =
        sfRectangleShape_getGlobalBounds(component->object->rectangle);

    component->features.rendered_rect = rect;
    sfRenderWindow_setFramerateLimit(app->window, app->state->framerate);
}
