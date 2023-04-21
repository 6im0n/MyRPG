/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** resume
*/

#include "event/global.h"
#include "components/components.h"
#include "lib/output.h"
#include "app/constants.h"
#include <fcntl.h>
#include <stdio.h>
#include "utils/file.h"
#include "lib/str.h"

void launch_game_resume(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    if (component->features.select == false)
        return;
    event_play_music(component, app);
    parsing_save(app);
    app->state->back = app->state->stage;
    app->state->stage = S_GAME;
}

static bool file_empty(void)
{
    char *data = file_load(SAVE_FILE);

    if (my_strcmp(data, "Empty") == 0)
        return true;
    return false;
}

void resume_available(node_component_t *component,
event_t *event, app_t *app)
{
    int fd = open(SAVE_FILE, O_RDONLY);
    sfColor color = {0, 0, 0, 100};

    (void) event;
    (void) app;
    if (fd == -1 || file_empty()) {
        component->features.select = false;
        sfText_setColor(component->object->text, color);
        return;
    }
    close(fd);
    component->features.select = true;
    sfText_setColor(component->object->text, sfBlack);
}
