/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** New component
*/

#ifndef NEW_H_
    #define NEW_H_
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "ressources/textures.h"
    #include "components/components.h"

/**
 * @brief New component type
 * @param ressources ressources
 * @param component components
 * @param objects objects
 * @param position position object
 */
void new_component_type(ressources_t ressources,
node_component_t *component, renderer_objects_t objects,
sfVector2f position);

/**
 * @brief New component size
 * @param component components
 * @param size size
 * @param rect rect
 */
void new_component_size(node_component_t *component,
sfVector2f size, sfIntRect rect);

/**
 * @brief New component set
 * @param component components
 * @param rect rect
 * @param type type
 * @param texture texture
 */
void new_component_set(node_component_t *component,
sfFloatRect rect, component_type_t type, texture_t texture);

#endif /* !NEW_H_ */
