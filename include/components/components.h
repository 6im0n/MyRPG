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

typedef struct s_components component_t;

typedef enum e_component_type {
    C_UNDEFINED,
    C_BUTTON,
    C_TYPES_LEN
} component_type_t;

typedef struct s_components {
    component_type_t type;
    renderer_objects_t *object;
    int state;
    sfFloatRect rendered_rect;
    component_t *next;
} component_t;

typedef struct s_main_components {
    component_t *start_menu;
    component_t *game;
} main_components_t;

/**
 * @brief Load all component
 * @param app 
 * @return main_components_t 
 */
main_components_t app_components_load(app_t *app);

/**
 * @brief Get component
 * @param app 
 * @return component_t* 
 */
component_t *components_get_start_menu(app_t *app);

/**
 * @brief Free component list
 * @param component_pure 
 */
void component_pure_free(component_t *component_pure);
#endif /* !COMPONENTS_H_ */
