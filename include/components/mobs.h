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

/**
 * @brief Create a mobs
 * @return mobs_t*
 */
mobs_t *mobs_create(ressources_t *ressources);

/**
 * @brief Destroyed a mobs
 * @param mobs
 */
void mobs_destroy(mobs_t *mobs);

void mobs_render_annimation(app_t *app);

void new_mobs_annimation(app_t *app, sfIntRect annimation, int index, int max);

void new_mobs_annimation(app_t *app, sfIntRect annimation, int index, int max);


#endif /* !mobs_H_ */
