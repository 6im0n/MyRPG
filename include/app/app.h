/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** app function
*/

#ifndef APP_H_
    #define APP_H_
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "components/components.h"

/**
 * @brief Run the app
 * main objects : window, clock
 */
int app_run(void);

/**
 * @brief Create a new app object which contains app
 * main objects : window, clock
 * @param window_mode Video mode to set to window object
 * @param window_title Title of app
 * @param window_frame_rate Frame rate to set to window object
 */
app_t app_create(ressources_t *ressources, sfVideoMode window_mode, char *window_title,
int window_frame_rate);

/**
 * @brief Create a icon for the application
 * @param window Need the windows
 */
void app_set_icon(sfRenderWindow *window, ressources_t *ressources);

/**
 * @brief Handle app events and dispatch them to components
 * @param app App object
 */
void app_handle_events(app_t *app);

/**
 * @brief Enable Mouse position with the reel coord
 * @return mouse_t 
 */
mouse_t mouse_init(void);

/**
 * @brief Initialisation of state app structure
 * @return state_t*
 */
state_t *state_new(void);

/**
 * @brief Destroyed state
 * @param state State to free
 */
void state_free(state_t *state);

/**
 * @brief Render app on screen
 * @param app App to render
 * @param ressources Ressources loaded to render sprites or any other
 * @param components Components to render
 */
void app_render(app_t *app, ressources_t *ressources, main_components_t *components);

/**
 * @brief Render component
 * @param app App to render
 * @param components Components to render
 */
void app_component_render(app_t *app, list_components_t *components);

/**
 * @brief Destroy given app and free all its ressources
 * @param app App to destroy
 */
void app_destroy(app_t *app);

#endif /* !APP_H_ */
