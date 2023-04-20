/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef mobs_H_
    #define mobs_H_

    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "components/components.h"
    #include "types/type.h"


/**
 * @brief Destroyed a mobs
 * @param mobs
 */
void mobs_destroy(list_mobs_t *list);

/**
 * @brief render a mobs
 * @param app
 */
void mobs_render_annimation(app_t *app);

/**
 * @brief create a new mobs annimation
 * @param mob
 * @param annimation
 * @param index
 * @param max
 * @return nothing
 */
void new_mobs_annimation(node_mob_t *mob,
sfIntRect annimation, int index, int max);

//MOBS LISTS//
/**
 * @brief create a new mobs list
 * @param void
 * @return list_mobs_t
 */
list_mobs_t *list_mobs_init(void);

/**
 * @brief add a new mobs to the list
 * @param list
 * @param ressources
 * @return list_mobs_t
 */
list_mobs_t *mobs_add(list_mobs_t *list, ressources_t ressources);

/**
 * @brief free the list
 * @param list
 * @return nothing
 */
void list_mobs_free(list_mobs_t *list);

/**
 * @brief append a new node to the list
 * @param list
 * @param node
 * @return nothing
 */
void list_mobs_append(list_mobs_t *list, node_mob_t *node);

/**
 * @brief init a new mob
 * @param ressources
 * @return node_mob_t
 */
node_mob_t *node_mobs_init(ressources_t ressources);

/**
 * @brief add a new mob to the list
 * @param app
 * @param ressources
 * @param possition
 */
void add_new_mob(app_t *app, ressources_t ressources, sfVector2f possition);

/**
 * @brief make the mob attack
 * @param mob
 * @param app
 */
void mobs_attack(node_mob_t *mob, app_t *app);

/**
 * @brief make the mob healt bar
 * @param mob
 * @param app
 */
void mob_health_bar(node_mob_t *mob, app_t *app);

/**
 * @brief make the mob move to the player
 * @param mob
 * @param app
 */
void mobs_move_to_player(node_mob_t *mob,
app_t *app);

/**
 * @brief detect if mob intersect player
 * @param app
 * @param mob
 */
bool mob_intersect_player(app_t *app, node_mob_t *mob);

/**
 * @brief finish the mob animation
 * @param mob
 */
bool finish_animation(node_mob_t *mob);
//-------//

#endif /* !mobs_H_ */
