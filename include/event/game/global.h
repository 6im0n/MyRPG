/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings
*/

#ifndef EVENT_GAME_H_
    #define EVENT_GAME_H_

    #include "components/components.h"

/**
 * @brief Close the application
 * @param component component
 * @param event event
 * @param app app
 */
void event_game_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Close the application
 * @param component component
 * @param event event
 * @param app app
 */
void move_player(node_component_t *component,
event_t *event, app_t *app);

void idle_player(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_GAME_H_ */
