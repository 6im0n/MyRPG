/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get
*/

#ifndef GET_COMPONENTS_H_
    #define GET_COMPONENTS_H_

    #include "types/type.h"
    #include "components/components.h"

/**
 * @brief Component cursor
 * @param app App
 * @param ressources Ressources
 * @param objects Objects
 * @param list List
 */
void component_cursor_default(app_t *app,ressources_t ressources,
list_components_t *list);

void components_get_cursor(app_t *app, ressources_t ressources,
                            list_components_t *list);

void event_cursor_onmove(node_component_t *component,
event_t *event, app_t *app);

//==================================================
// START MENU
//==================================================

/**
 * @brief get components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return main_components_t
 */
void components_get_start_menu(app_t *app,
ressources_t ressources, list_components_t *mstart_menu);

/**
 * @brief components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return list_components_t*
 */
void components_menu_start(app_t *app,ressources_t ressources,
list_components_t *mstart_menu);

//==================================================
// HELP MENU
//==================================================

/**
 * @brief get components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return main_components_t
 */
void components_get_help_menu(app_t *app, ressources_t ressources,
list_components_t *mstart_menu);

/**
 * @brief components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return list_components_t*
 */
void components_menu_help(app_t *app,ressources_t ressources,
list_components_t *mstart_menu);

void components_help_bouton_move(app_t *app, ressources_t ressources,
list_components_t *list);

void components_help_command_setting(app_t *app, ressources_t ressources,
list_components_t *list);

void components_help_command_inventory(app_t *app, ressources_t ressources,
list_components_t *list);

//==================================================
// LOAD GAME
//==================================================

/**
 * @brief Components Inventory
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void components_get_load_game(app_t *app, ressources_t ressources,
list_components_t *list);

/**
 * @brief Components init Inventory
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void components_load_game(app_t *app,ressources_t ressources,
list_components_t *list);

void component_load_game_bouton(app_t *app, ressources_t ressources,
list_components_t *list);

//==================================================
// INVENTORY
//==================================================

/**
 * @brief Components Inventory
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void components_get_inventory(app_t *app, ressources_t ressources,
list_components_t *list);

/**
 * @brief Components init Inventory
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void components_inventory(app_t *app,ressources_t ressources,
                            list_components_t *list);

/**
 * @brief Components set Inventory slot
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void inventory_object(app_t *app, ressources_t ressources,
list_components_t *list);

/**
 * @brief Components set Inventory selector slot
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void inventory_object_select(app_t *app, ressources_t ressources,
list_components_t *list);

//==================================================
// SETTING
//==================================================

/**
 * @brief Components Setting
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void components_get_setting(app_t *app, ressources_t ressources,
list_components_t *list);

/**
 * @brief Components init Setting
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
void components_setting(app_t *app,ressources_t ressources,
list_components_t *list);

void components_menu_setting_selector_sound(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_volume_music(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_volume_music_cursor(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_volume_sound(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_volume_sound_cursor(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_volume_music_title(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_volume_sound_title(app_t *app,
ressources_t ressources, list_components_t *list);

void components_setting_bouton_quit(app_t *app, ressources_t ressources,
list_components_t *list);

void components_setting_bouton_resume(app_t *app, ressources_t ressources,
list_components_t *list);

void components_setting_bouton_fullscreen(app_t *app, ressources_t ressources,
list_components_t *list);

void components_menu_setting_selector_framelimit(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_framelimit_cursor(app_t *app,
ressources_t ressources, list_components_t *list);

void components_menu_setting_selector_framerate_title(app_t *app,
ressources_t ressources, list_components_t *list);

void components_resolution_1(app_t *app, ressources_t ressources,
list_components_t *list);

void components_resolution_2(app_t *app, ressources_t ressources,
list_components_t *list);

void components_resolution_3(app_t *app, ressources_t ressources,
list_components_t *list);

//==================================================
// GAME
//==================================================

/**
 * @brief Components Inventory
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
list_components_t *components_get_game(app_t *app,
ressources_t ressources, list_components_t *list);

/**
 * @brief Components init Inventory
 * @param app App
 * @param ressources ressources
 * @param list list
 */
void components_game(app_t *app, ressources_t ressources,
list_components_t *list);

//==================================================
// NEW GAME
//==================================================

/**
 * @brief Components new game
 * @param app App
 * @param ressources ressources
 * @param list list
 * @return list_components_t*
 */
list_components_t *components_get_new_game(app_t *app,
ressources_t ressources, list_components_t *list);

/**
 * @brief Components init new game
 * @param app App
 * @param ressources ressources
 * @param list list
 */
void components_new_game(app_t *app,ressources_t ressources,
list_components_t *list);

#endif /* !GET_COMPONENTS_H_ */
