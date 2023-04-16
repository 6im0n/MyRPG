/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "components/components.h"
    #include "ressources/quests.h"

/**
 * @brief Create a player
 * @return player_t*
 */
player_t *player_create(ressources_t *ressources);

/**
 * @brief Destroyed a player
 * @param player
 */
void player_destroy(player_t *player);

/**
 * @brief Add item to player
 * @param app
 * @param item
 */
void add_item_player(app_t *app, item_t item);

/**
 * @brief Switch item into list
 * @param list list
 * @param slot_1 item select for switch
 * @param slot_2 item to change slot
 */
void player_item_switch(list_item_t *list, component_id_t slot_1,
component_id_t slot_2);

void swap_item_player(list_item_t *list,
component_id_t slot_1, component_id_t slot_2);

void list_item_delete(list_item_t *list, component_id_t slot);

void event_key_switch(node_component_t *component,
event_t *event, app_t *app);

void player_render_annimation(app_t *app);

void new_player_annimation(app_t *app, sfIntRect annimation, int index,
                            int max);

/**
 * @brief Append quests system
 * @param list list
 * @param quest quest
 */
void quest_append(list_quests_t *list, quests_t quest);

/**
 * @brief Set quests node
 * @param app app
 * @param node node
 */
void quests_set_text_position(app_t *app, node_quests_t *node);

void quests_current_add(list_quests_t *list, quests_t id);

#endif /* !PLAYER_H_ */
