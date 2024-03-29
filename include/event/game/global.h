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
 * @brief Get availaible directions
 * @param array bool array
 * @param position sfVector2f position
 * @param player Player structure
 */
void collisions(bool *array, sfVector2f position, player_t *player);

/**
 * @brief Save Game in game
 * @param component component
 * @param event event
 * @param app app
 */
void save_game_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Handle beacon events healt
 * @param component component
 * @param event event
 * @param app app
 */
void beacon_healt_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Handle beacon skill
 * @param component component
 * @param event event
 * @param app app
 */
void beacon_skill_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Disable a beacon
 * @param component component
 * @param event event
 * @param app app
 */
void beacon_events_ondisabled(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Disable the beacon item
 * @param component component
 * @param event event
 * @param app app
 */
void beacon_item_events_ondisabled(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Handle beacon item
 * @param component component
 * @param event event
 * @param app app
 */
void beacon_item_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Handle the mob generation of the mob when player is near to a area
 * @param component component
 * @param event event
 * @param app app
 */
void generation_mob_next_to(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Disable the mob generation
 * @param component component
 * @param event event
 * @param app app
 */
void generation_mob_ondisabled(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Handle the screen when player is dead
 * @param component component
 * @param event event
 * @param app app
 */
void event_death_back_home(node_component_t *component,
event_t *event, app_t *app);

void altar_onkeypress(node_component_t *component,
event_t *event, app_t *app);

void altar_events_ondisabled(node_component_t *component,
event_t *event, app_t *app);

void quest_gestion_xp(app_t *app);

#endif /* !EVENT_GAME_H_ */
