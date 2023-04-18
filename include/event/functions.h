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
    #include "event/game/dialog.h"
    #include "event/game/global.h"

typedef void (*parsing_handler_t)(node_component_t *component,
event_t *event, app_t *app);

static const parsing_handler_t clicked_event[CLICKED_LEN] = {
    [MENU_LOAD_GAME] = &event_open_load_game_onclick,
    [MENU_HELP] = &event_open_help_onclick,
    [QUIT_APP] = &event_quit_app_onclick,
    [MENU_SETTINGS] = &event_open_setting_onclick,
    [MENU_OPEN_HOME] = &event_help_bouton_home_onclick,
    [GAME_LUNCH] = &launch_game,
    [CHARACTER_SELECT_1] = &event_character1_select_onclick,
    [CHARACTER_SELECT_2] = &event_character2_select_onclick,
    [CHARACTER_SELECT_3] = &event_character3_select_onclick
};

static const parsing_handler_t hover_event[HOVER_LEN] = {
    [ACTIVE_ANIMATION] = &event_active_annimation
};

static const parsing_handler_t disable_event[DISABLED_LEN] = {
    [DISABLED_ANIMATION] = &event_pause_annimation,
    [QUEST_MAIN_FIRST_DIALOG] = &dialog_main_quests_disabled
};

static const parsing_handler_t nonclicked_event[NONCLICKED_LEN] = {
};

static const parsing_handler_t pressed_event[KEYPRESSED_LEN] = {
    [QUEST_MAIN_FIRST_DIALOG_PRESSED] = &dialog_main_quests_onkeypress,
    [BEACON_HEAL_PRESSED] = &beacon_healt_onkeypress,
    [BEACON_SKILL_PRESSED] = &beacon_skill_onkeypress
};

static const parsing_handler_t released_event[KEYRELEASED_LEN] = {
};

static const parsing_handler_t moved_event[MOVED_LEN] = {
};

static const parsing_handler_t next_to_event[NEXT_TO_LEN] = {
    [QUEST_MAIN_FIRST_DIALOG_NEXTTO] = &dialog_main_quests_next_to,
    [QUEST_MAIN_FIRST_OBJ_DIALOG_NEXTTO] = &dialog_main_quests_onnext_to
};

#endif /* !EVENT_SETTINGS_H_ */
