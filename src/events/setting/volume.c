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
#include "event/global.h"

void event_settings_selector_mute_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (ST_IS_CLICKED(component))
        app->state->sound->mute = !app->state->sound->mute;
    component->features.select = app->state->sound->mute;
    if (app->state->sound->mute == false)
        sfSound_pause(app->state->sound->music);
    else
        sfSound_play(app->state->sound->music);
    sfSound_setVolume(component->object->sound,
        app->state->sound->volume_music);
    component->state = ST_SET_CLICKED(component, false);
}

static void set_volume_string(app_t *app, node_component_t *component,
int volume)
{
    char *string = malloc(my_nbrlen(volume) + 3);

    my_strcpy(string, my_char(volume));
    my_strcat(string, " %\0");
    sfText_setString(component->prev->object->text, string);
    if (component->prev->id == ID_MUSIC_CURSOR) {
        app->state->sound->volume_music = volume;
        sfSound_setVolume(app->state->sound->music, volume);
    } else {
        app->state->sound->volume_sound = volume;
        sfSound_setVolume(app->state->sound->sound, volume);
    }
}

void event_settings_selector_volume_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    if (!component || (component->prev->id != ID_MUSIC_CURSOR &&
        component->prev->id != ID_SOUND_CURSOR))
        return;
    if (component->prev->id == ID_MUSIC_CURSOR)
        sfText_setString(component->prev->object->text, "Music Volume");
    else
        sfText_setString(component->prev->object->text, "Sound Volume");
}

void event_settings_selector_volume_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    sfFloatRect prev = component->prev->features.rendered_rect;
    sfVector2f pos = sfRectangleShape_getPosition(
        component->object->rectangle);
    sfVector2f max = { component->prev->features.rendered_rect.left,
        component->prev->features.rendered_rect.left +
        component->prev->features.rendered_rect.width
    };
    int volume = 0;

    pos.x = app->mouse.position.x;
    if (pos.x >= max.x && pos.x <= max.y) {
        sfRectangleShape_setPosition(component->object->rectangle, pos);
        volume = ((pos.x - prev.left) / prev.width) * 100;
        set_volume_string(app, component, volume);
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
