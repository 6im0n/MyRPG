/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#ifndef EVENT_START_MENU_BOUTON_H_
    #define EVENT_START_MENU_BOUTON_H_

    #include "types/types.h"
    #include "components/components.h"

/**
 * @brief On click action for bouton play
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_bouton_play_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief On click action for bouton help
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_help_bouton_home_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_menu_onkeypress(node_component_t *component,
event_t *event, app_t *app);

void event_menu_help_onkeypress(node_component_t *component,
event_t *event, app_t *app);

void event_bouton_help_move_ondisabled(node_component_t *component,
event_t *event, app_t *app);

void event_bouton_help_open_inventory_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_bouton_help_close_onclick(node_component_t *component,
event_t *event, app_t *app);

void event_bouton_help_onhover(node_component_t *component,
event_t *event, app_t *app);

void event_bouton_help_ondisabled(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_START_MENU_BOUTON_H_ */
