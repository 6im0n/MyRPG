/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_
    #include <stdbool.h>
    #include <SFML/Graphics.h>

//==================================================
// APP
//==================================================

typedef struct s_app {
    sfRenderWindow *window;
} app_t;

//==================================================
// RESSOURCES
//==================================================

typedef struct s_ressources {
    sfTexture **textures;
} ressources_t;

typedef struct s_event {
    sfEvent original;
} event_t;

//==================================================
// RENDERERING
//==================================================

typedef struct s_render_objects {
    sfRenderWindow *window;
    sfView *view;
    sfSprite *sprite;
    sfText *text;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
} renderer_objects_t;

typedef struct s_renderer {
    renderer_objects_t *objects;
    ressources_t *ressources;
} renderer_t;

#endif /* !TYPES_H_ */
