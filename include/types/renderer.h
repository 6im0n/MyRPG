/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** renderer
*/

#ifndef RENDERER_H_
    #define RENDERER_H_
    #include "type.h"
    #include <SFML/Graphics.h>
    #include "components/components.h"

//==================================================
// RENDERER OBJECTS
//==================================================

/**
 * @brief Create a new renderer object
 * @param window Existing window to insert in renderer
 * @return Renderer objects created
 */
renderer_objects_t renderer_objects_create(sfRenderWindow *window);

/**
 * @brief Destroy given renderer objects
 * @param objects Objects to destroy
 */
void renderer_objects_destroy(renderer_objects_t *objects);

/**
 * @brief Change effect botton
 * @param app app
 * @param component components
 */
void render_button_effect(app_t *app, node_component_t *component);

#endif /* !RENDERER_H_ */
