/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#ifndef EVENT_SETTING_H_
    #define EVENT_SETTING_H_

    #include "types/types.h"
    #include "components/components.h"

/**
 * @brief Close setting when Key E PRESSED
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_key_settings_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app);

void event_settings_open_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_setting_close_windows_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_settings_selector_mute_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_settings_selector_volume_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_settings_selector_volume_onnonclick(node_component_t *component,
event_t *event, app_t *app);

void event_settings_selector_volume_ondisabled(node_component_t *component,
event_t *event, app_t *app);

void event_close_onclick(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_SETTING_H_ */
