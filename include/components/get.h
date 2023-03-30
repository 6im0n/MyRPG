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
list_components_t *components_get_start_menu(app_t *app,
ressources_t ressources, renderer_objects_t objects,
list_components_t *mstart_menu);

/**
 * @brief components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return list_components_t*
 */
list_components_t *components_menu_start(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *mstart_menu);

void bouton_play(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list);

void bouton_help(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list);

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
list_components_t *components_get_help_menu(app_t *app,
ressources_t ressources, renderer_objects_t objects,
list_components_t *mstart_menu);

/**
 * @brief components start menu
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @param mstart_menu list start menu
 * @return list_components_t*
 */
list_components_t *components_menu_help(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *mstart_menu);

#endif /* !GET_COMPONENTS_H_ */
