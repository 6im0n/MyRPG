/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** buttons
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_

    #include "types/type.h"
    #include "components/components.h"

/**
 * @brief Append button from file
 * @param app main structure
 * @param ressources ressources structure
 * @param list list of components
 * @param filepath char *
 */
void parsing_buttons(app_t *app, ressources_t ressources,
                    list_components_t *list, char *filepath);

#endif /* BUTTONS_H_ */
