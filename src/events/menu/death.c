/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** death
*/

#include "components/components.h"
#include <stdio.h>
#include "app/constants.h"
#include "types/list.h"
#include "event/start_menu/bouton.h"

void event_death_back_home(node_component_t *component,
event_t *event, app_t *app)
{
    FILE *fd = fopen(SAVE_FILE, "w");

    (void) component;
    (void) event;
    fwrite("Empty" , 1 , 5 , fd );
    app->state->stage = S_MENU_LOAD_GAME;
    app->game = false;
    fclose(fd);
    clear_old_game(app);
}
