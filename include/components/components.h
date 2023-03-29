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
    #include "ressources/textures.h"

typedef enum e_component_type {
    C_UNDEFINED,
    C_TYPES_RECTANGLE,
    C_TYPES_CIRCLE,
    C_TYPES_TEXT,
    C_TYPES_SPRITE,
    C_TYPES_LEN
} component_type_t;

typedef struct s_node_components {
    int state;
    component_type_t type;
    renderer_objects_t *object;
    texture_t texture;
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
 * @brief Load component
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @return main_components_t
 */
main_components_t app_components_load(app_t *app, ressources_t ressources,
renderer_objects_t objects);

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
 * @brief Free component
 * @param components main components structure
 */
void components_free(main_components_t *components);

/**
 * @brief Init pure component
 * @param size App size
 * @return node_component_t*
 */
node_component_t *component_pure_new(sfVector2u size);

#endif /* !COMPONENTS_H_ */
