/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** app function
*/

#ifndef APP_H_
    #define APP_H_

    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "components/components.h"
    #include <stdio.h>

/**
 * @brief Run the app
 */
int app_run(void);

/**
 * @brief Create a new app object which contains app
 * main objects : window, clock
 * @param window_title Title of app
 * @param window_frame_rate Frame rate to set to window object
 */
app_t app_create(char *window_title, int window_frame_rate);

/**
 * @brief Create a icon for the application
 * @param window Need the windows
 */
void app_set_icon(sfRenderWindow *window, ressources_t *ressources);

/**
 * @brief Handle app events and dispatch them to components
 * @param app App object
 * @param components Components
 */
void app_handle_events(app_t *app, main_components_t *components);

/**
 * @brief Enable Mouse position with the reel coord
 * @return mouse_t struct
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
void app_render(app_t *app, ressources_t *ressources,
main_components_t *components);

/**
 * @brief Render component
 * @param app App to render
 * @param components Components to render
 */
void app_component_render(app_t *app, list_components_t *components);

/**
 * @brief Render stuff in game
 * @param app struct
 * @param list list components
 */
void render_in_game(app_t *app, list_components_t *list);

/**
 * @brief Destroy given app and free all its ressources
 * @param app App to destroy
 */
void app_destroy(app_t *app);

/**
 * @brief Create element
 * @param element element
 * @param ressources ressources
 */
void app_create_all_item(elements_t *element,
ressources_t *ressources);

/**
 * @brief Save game application
 * @param app app
 */
void app_save_game(app_t *app);

/**
 * @brief Create new pop up
 * @param app app
 * @param type type
 * @param time time
 */
void new_popup(app_t *app, type_popup_t type, int time);;

/**
 * @brief Render popup
 * @param app app
 */
void popup_render(app_t *app);

/**
 * @brief Load app
 * @param app app
 * @param ressources ressources
 */
void app_load(app_t *app, ressources_t *ressources);

/**
 * @brief Loader initialization
 * @return loader_t*
 */
loader_t *loader_init(void);

/**
 * @brief Display the loader
 * @param app app
 * @param shape shape
 */
void loader_display(app_t *app, sfRectangleShape *shape);

/**
 * @brief Display loader text
 * @param app app
 * @param shape shape
 * @param content content
 */
void loader_text_display(app_t *app, sfRectangleShape *shape, char *content);

/**
 * @brief Render player and inventory
 * @param app app
 */
void app_player_render(app_t *app);

/**
 * @brief Render quests
 * @param app app
 */
void app_quests_dispatch(app_t *app);

/**
 * @brief Display inventory in order to save
 * @param fd file descriptor
 * @param inventory list of items
 */
void display_inventory(FILE *fd, list_item_t *inventory);

/**
 * @brief Display inventory in order to save
 * @param fd file descriptor
 * @param quests list of quest
 */
void display_quest(FILE *fd, list_quests_t *quests);

bool quests_get_finish(app_t *app, list_quests_t *list,
quests_t id, speech_id_t speech);

/**
 * @brief Init layers
 * @param app struct
 * @param ressources ressources
 */
void layers_init(app_t *app, ressources_t ressources);

/**
 * @brief Render layers
 * @param app struct
 */
void layer_render(app_t *app);

#endif /* !APP_H_ */
