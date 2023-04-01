/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#ifndef EVENT_INVENTORY_H_
    #define EVENT_INVENTORY_H_

    #include "types/types.h"
    #include "components/components.h"

/**
 * @brief Open inventory when Key E PRESSED
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Close inventory when Key E PRESSED
 * @param component Component
 * @param event Event
 * @param app App
 */
void event_key_inventory_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app);

void event_selector_onpress(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_INVENTORY_H_ */
