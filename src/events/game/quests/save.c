/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** save
*/

#include "app/app.h"
#include "components/speech.h"

void save_game_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) component;
    if (!ST_IS_NEAR(component))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        component->features.visited++;
        app_save_game(app);
        new_popup(app, P_SAVE, 5);
        if (component->features.visited == 1)
            quests_get_finish(app, app->element->quests,
            Q_SAVE, SP_QUEST_BACK_TALK_NPC_2);
        else
            new_speech(app, SP_SAVE);
    }
}
