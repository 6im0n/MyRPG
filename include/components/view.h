/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** view
*/

#ifndef VIEW_H_
    #define VIEW_H_

    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "components/components.h"

/**
 * @brief Manage view and responsivity
 * @param app App structure
 * @param event Event structure
 * @param components Components structure
 */
void manage_view(app_t *app, event_t *event, main_components_t *components);

#endif /* !VIEW_H_ */
