/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** concat_item
*/

#include "event/global.h"
#include "components/components.h"
#include "lib/output.h"
#include "app/constants.h"
#include <fcntl.h>
#include <stdio.h>
#include "lib/str.h"
#include "lib/tools.h"
#include "parsing/utils.h"
#include "app/app.h"

static char *concat_data(char *prefix, char *data)
{
    int len_prefix = my_strlen(prefix);
    int len_data = my_strlen(data);
    int len = len_prefix + len_data + 4;
    char *save = malloc(sizeof(char) * (len + 1));

    clean_char(save, len + 1);
    if (!save)
        return NULL;
    my_strcpy(save, prefix);
    my_strcat(save, data);
    my_strcat(save, "/10");
    return save;
}

void concat_item_skills(node_item_t *item, skills_t skills)
{
    char *temp = concat_data(item->sharpness, my_char(skills.strength));
    item->sharpness = temp;
    temp = concat_data(item->weight, my_char(skills.speed));
    item->weight = temp;
}
