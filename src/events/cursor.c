/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** curosr
*/


#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"

void event_play_music(node_component_t *component,
app_t *app)
{
    if (component->features.styles.sound == SD_NONE)
        return;
    sfSound_setVolume(component->object->sound,
        app->state->sound->volume_sound);
    sfSound_play(component->object->sound);
}

void event_cursor_onmove(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    node_component_t *tmp = component->next;
    sfVector2f position = {
        app->mouse.position.x + 12,
        app->mouse.position.y + 14.5};
    sfVector2f size = {40, 45};
    sfVector2f sizesmall = {40 / 3, 45 / 3};

    if (app->state->stage == S_GAME)
        sfRectangleShape_setSize(tmp->object->rectangle, sizesmall);
    else
        sfRectangleShape_setSize(tmp->object->rectangle, size);
    sfRectangleShape_setPosition(tmp->object->rectangle, position);
    tmp->features.rendered_rect =
    sfRectangleShape_getGlobalBounds(tmp->object->rectangle);
}

void event_quit_app_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    sfRenderWindow_close(app->window);
}

void event_close_current_stage_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    app->state->stage = app->state->back;
}
