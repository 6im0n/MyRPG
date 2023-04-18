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

void mobs_render_annimation(app_t *app);

void new_mobs_annimation(node_mob_t *mob,
sfIntRect annimation, int index, int max);

//MOBS LISTS//
list_mobs_t *list_mobs_init(void);

list_mobs_t *mobs_add(list_mobs_t *list, ressources_t ressources);

void list_mobs_free(list_mobs_t *list);

void list_mobs_append(list_mobs_t *list, node_mob_t *node);

node_mob_t *node_mobs_init(ressources_t ressources);

void add_new_mob(app_t *app, ressources_t ressources, sfVector2f possition);

void mobs_attack(node_mob_t *mob,
app_t *app);

void mobs_move_to_player(node_mob_t *mob,
app_t *app);

bool finish_animation(node_mob_t *mob);
//-------//

void list_mob_delete(list_mobs_t *list);

#endif /* !mobs_H_ */
