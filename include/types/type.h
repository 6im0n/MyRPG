/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

//==================================================
// STATE
//==================================================

typedef enum e_stage_type {
    S_START_MENU,
    S_LEN
} stage_t;

typedef struct s_sounds {
    sfSound *old;
    sfSound *new;
    int stage_level;
    int volume;
    bool mute;
} sounds_t;

typedef struct s_states {
    stage_t stage;
    bool transition;
    sounds_t *sound;
} state_t;

//==================================================
// APP
//==================================================

typedef struct s_mouse {
    bool pressed;
    sfVector2f press_position;
    sfVector2f last_move_position;
    sfVector2f move_diff;
    sfVector2f position;
} mouse_t;

typedef struct s_app {
    sfRenderWindow *window;
    mouse_t mouse;
    state_t *state;
} app_t;

typedef struct s_event {
    sfEvent original;
    mouse_t *mouse;
} event_t;

//==================================================
// RESSOURCES
//==================================================

typedef struct s_ressources {
    sfTexture **textures;
    sfSoundBuffer **sounds;
} ressources_t;

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
