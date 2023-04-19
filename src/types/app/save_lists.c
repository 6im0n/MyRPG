/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** save_skills
*/

#include <stdio.h>
#include "components/components.h"
#include "lib/tools.h"
#include "lib/str.h"

static void add_item_display(node_item_t *tmp, FILE *fd)
{
    char *str = my_char(tmp->item);
    int lenf = my_strlen(str);

    fwrite( str, 1 , lenf , fd );
    if (tmp->next != NULL) {
        fwrite(" " , 1 , 1 , fd );
    }
    free(str);
}

void display_inventory(FILE *fd, list_item_t *inventory)
{
    node_item_t *tmp = inventory->first;

    fwrite("Inventory: " , 1 , 11 , fd );
    while (tmp != NULL) {
        add_item_display(tmp, fd);
        tmp = tmp->next;
    }
    fwrite("\n" , 1 , 1 , fd );
}

static void add_quest_display(node_quests_t *tmp, FILE *fd)
{
    char *current = my_char(tmp->current);
    int len_current = my_strlen(current);
    char *str = my_char(tmp->id);
    int len_str = my_strlen(str);

    fwrite( str, 1 , len_str , fd );
    fwrite("|", 1, 1, fd);
    fwrite( current, 1 , len_current , fd );
    if (tmp->next != NULL)
        fwrite( " ", 1 , 1 , fd );
    free(current);
    free(str);
}

void display_quest(FILE *fd, list_quests_t *quests)
{
    node_quests_t *tmp = quests->first;

    fwrite("Quest: " , 1 , 7 , fd );
    while (tmp != NULL) {
        add_quest_display(tmp, fd);
        tmp = tmp->next;
    }
    fwrite("\n" , 1 , 1 , fd );
}
