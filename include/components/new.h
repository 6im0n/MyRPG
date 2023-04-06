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
node_component_t *component, sfVector2f position);

/**
 * @brief New component size
 * @param component components
 * @param size size
 * @param rect rect
 * @param e_size e_size
 */
void new_component_size(node_component_t *component,
sfVector2f size, sfIntRect rect, component_size_t e_size);

/**
 * @brief New component set
 * @param component components
 * @param rect rect
 * @param type type
 * @param style texture sound and font
 */
void new_component_set(node_component_t *component,
sfFloatRect rect, component_type_t type, component_styles style);

/**
 * @brief Set string if components type == text
 * @param component components
 * @param string string to draw
 * @param color color
 * @param size size
 */
void set_component_text(node_component_t *component,
char *string, sfColor color, int size);

/**
 * @brief Set the component text position
 * @param component component
 * @param position position
 * @param middle for center the text
 */
void set_component_text_pos(node_component_t *component,
sfVector2f position, int middle);

/**
 * @brief Set id for inventory object
 * @param node node components
 */
void inventory_object_add_id(node_component_t *node);

/**
 * @brief Set annimation for object
 * @param component component
 * @param annimation annimation movement
 * @param index index to start the annimation
 * @param max max index
 */
void new_component_annimation(node_component_t *component,
sfIntRect annimation, int index, int max);

/**
 * @brief Add new item
 * @param id id
 * @param irect floatrect
 * @param frect intrect
 * @return node_item_t*
 */
node_item_t *new_items(node_item_t *item, item_t id, sfIntRect irect,
sfFloatRect frect);

/**
 * @brief Add texture
 * @param item item
 * @param ressources ressources
 * @param item_texture item texture
 * @param position position item
 */
void new_items_texture(node_item_t *item, ressources_t *ressources,
texture_t item_texture, sfVector2f position);

/**
 * @brief Set size item
 * @param item item
 * @param size size
 */
void new_items_size(node_item_t *item, sfVector2f size);

#endif /* !NEW_H_ */
