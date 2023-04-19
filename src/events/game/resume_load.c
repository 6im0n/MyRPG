/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** resume_load
*/

#include "event/global.h"
#include "components/components.h"
#include "ressources/loaders/textures.h"
#include "lib/output.h"
#include "app/constants.h"
#include <fcntl.h>
#include <stdio.h>
#include "utils/file.h"
#include "lib/str.h"
#include "lib/tools.h"
#include "components/player.h"
#include "lib/tools.h"

static void set_texture(player_t *player)
{
    sfTexture *texture = sfTexture_createFromFile(
        textures_loaders[player->character->tx], NULL);

    sfRectangleShape_setTexture(player->character->shape, texture, sfFalse);
}

static void get_player(player_t *player, char *str)
{
    int texture = my_strlen("Texture_player");
    int position = my_strlen("Position");
    int len_posx = 0;
    sfVector2f pos = { 0, 0 };

    if (my_strncmp("Texture_player", str, texture) == 0) {
        player->character->tx = my_int(str + texture + 2);
        set_texture(player);
    }
    if (my_strncmp("Position", str, position) == 0) {
        pos.x = my_int(str + position + 2);
        len_posx = my_nbrlen(pos.x);
        pos.y = my_int(str + position + 2 + len_posx + 1);
        sfRectangleShape_setPosition(player->character->shape, pos);
    }
}

static void interpreter(app_t *app,
char *file, int index_line, int explore)
{
    char *str = malloc(sizeof(char) * (index_line + 1));

    if (!str)
        return;
    my_strncpy(str, file + explore, index_line);
    get_skills(app, str);
    get_player(app->element->player, str);
    free(str);
}

void parsing_save(app_t *app)
{
    char *file = file_load(SAVE_FILE);
    int index = 0;
    int index_line = 0;
    int explore = 0;

    while (file[index] != '\0') {
        do {
            index_line++;
            index++;
        } while (file[index] != '\n');
        interpreter(app, file, index_line, explore);
        index_line = 0;
        index++;
        explore = index;
    }
    free(file);
}
