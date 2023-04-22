/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** dialog
*/

#ifndef DIALOG_H_
    #define DIALOG_H_

    #include "components/components.h"

/**
 * @brief Main_dialog_PNJ
 * @param component component
 * @param event event
 * @param app app
 */
void dialog_main_quests_next_to(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Main_dialog_PNJ_disabled
 * @param component component
 * @param event event
 * @param app app
 */
void dialog_main_quests_disabled(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Lunch discution main quests
 * @param component component
 * @param event event
 * @param app app
 */
void dialog_main_quests_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Lunch discution main quests
 * @param component component
 * @param event event
 * @param app app
 */
void dialog_main_quests_onnext_to(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Lunch discution save quest
 * @param component component
 * @param event event
 * @param app app
 */
void dialog_save_quests_onnext_to(node_component_t *component,
event_t *event, app_t *app);

#endif /* !DIALOG_H_ */
