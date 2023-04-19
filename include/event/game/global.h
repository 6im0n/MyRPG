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

void idle_player(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Get availaible directions
 * @param array bool array
 * @param position sfVector2f position
 * @param player Player structure
 */
void collisions(bool *array, sfVector2f position, player_t *player);

void beacon_healt_onkeypress(node_component_t *component,
event_t *event, app_t *app);

void beacon_skill_onkeypress(node_component_t *component,
event_t *event, app_t *app);

void beacon_events_ondisabled(node_component_t *component,
event_t *event, app_t *app);

void generation_mob_next_to(node_component_t *component,
event_t *event, app_t *app);

void generation_mob_ondisabled(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_GAME_H_ */
