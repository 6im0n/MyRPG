/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef COMPONENTS_H_
    #define COMPONENTS_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"

typedef enum e_component_type {
    C_UNDEFINED,
    C_BUTTON,
    C_TYPES_LEN
} component_type_t;

typedef struct s_node_components {
    int state;
    component_type_t type;
    renderer_objects_t *object;
    sfFloatRect rendered_rect;
    struct s_node_components *next;
    struct s_node_components *prev;
} node_component_t;

typedef struct s_list_components {
    node_component_t *first;
    node_component_t *last;
    int len;
} list_components_t;

typedef struct s_main_components {
    list_components_t *start_menu;
    list_components_t *game;
} main_components_t;

/**
 * @brief Load all component
 * @param app struct
 * @return main_components_t node
 */
main_components_t app_components_load(app_t *app);

/**
 * @brief Get First Node component
 * @param app app
 * @return node_component_t* node
 */
node_component_t *components_get_start_menu(app_t *app);

/**
 * @brief Free component
 * @param components main components structure
 */
void components_free(main_components_t *components);

#endif /* !COMPONENTS_H_ */
