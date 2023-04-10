/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** functions
*/



#ifndef EVENT_FUNCTIONS_H_
    #define EVENT_FUNCTIONS_H_

    #include "event/global.h"
    #include "event/annimation.h"
    #include "components/components.h"
    #include "event/start_menu/bouton.h"

typedef void (*parsing_handler_t)(node_component_t *component,
event_t *event, app_t *app);

static const parsing_handler_t clicked_event[CLICKED_LEN] = {
    [MENU_LOAD_GAME] = &event_open_load_game_onclick,
    [MENU_HELP] = &event_open_help_onclick,
    [QUIT_APP] = &event_quit_app_onclick,
    [MENU_SETTINGS] = &event_open_setting_onclick
};

static const parsing_handler_t hover_event[HOVER_LEN] = {
    [ACTIVE_ANIMATION] = &event_active_annimation
};

static const parsing_handler_t disable_event[DISABLED_LEN] = {
    [DISABLED_ANIMATION] = &event_pause_annimation
};

static const parsing_handler_t nonclicked_event[NONCLICKED_LEN] = {
};

static const parsing_handler_t pressed_event[KEYPRESSED_LEN] = {
};

static const parsing_handler_t released_event[KEYRELEASED_LEN] = {
};

static const parsing_handler_t moved_event[MOVED_LEN] = {
};

#endif /* !EVENT_SETTINGS_H_ */
