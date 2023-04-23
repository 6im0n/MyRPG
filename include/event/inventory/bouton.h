/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#ifndef EVENT_INVENTORY_H_
    #define EVENT_INVENTORY_H_

    #include "components/components.h"
    #define M_PI 3.14159265358979323846
/**
 * @brief Open inventory when Key E PRESSED
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Close inventory when Key E PRESSED
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_key_inventory_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief handle inventory selector
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_selector_onpress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief handle inventory help button
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_bouton_help_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief handle inventory item hover
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void item_player_hover(node_component_t *component, event_t *event, app_t *app);

/**
 * @brief handle inventory item equip
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void inventory_equip_item(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief handle item delete from inventory
 *
 * @param component Component
 * @param event Event
 * @param app App
 */
void inventory_delete_item(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Handle inventory skill button
 *
 * @param component
 * @param event
 * @param app
 */
void event_inventory_skill_onpressed(node_component_t *component,
event_t *event, app_t *app);

void event_item_info_ondisabled(node_component_t *component,
event_t *event, app_t *app);

void event_inventory_skill_ondisabled(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_INVENTORY_H_ */
