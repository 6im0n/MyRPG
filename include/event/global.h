/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings
*/

#ifndef EVENT_SETTINGS_H_
    #define EVENT_SETTINGS_H_

    #include "components/components.h"

/**
 * @brief Close the application
 * @param component component
 * @param event event
 * @param app app
 */
void event_quit_app_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Close current stage
 * @param component component
 * @param event event
 * @param app app
 */
void event_close_current_stage_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Open Setting dialog
 * @param component component
 * @param event event
 * @param app app
 */
void event_open_setting_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Open help dialog
 * @param component component
 * @param event event
 * @param app app
 */
void event_open_help_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Play music
 * @param component component
 * @param app app
 */
void event_play_music(node_component_t *component,
app_t *app);

/**
 * @brief Event set update player with parsing
 * @param app app;
 */
void parsing_save(app_t *app);

/**
 * @brief Get the skills object
 * @param app struct
 * @param str char *
 */
void get_skills(app_t *app, char *str);

#endif /* !EVENT_SETTINGS_H_ */
