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
void mobs_destroy(list_mobs_t *mobs);

void mobs_render_annimation(app_t *app);

void new_mobs_annimation(node_mobs_t *mobs,
sfIntRect annimation, int index, int max);

//MOBS LISTS//
list_mobs_t *list_mobs_init(void);

list_mobs_t *mobs_add(list_mobs_t *mobs_list, ressources_t ressources);

void list_mobs_free(list_mobs_t *list);

void list_mobs_append(list_mobs_t *list, node_mobs_t *node);

node_mobs_t *node_mobs_init(ressources_t ressources);
//-------//

#endif /* !mobs_H_ */
