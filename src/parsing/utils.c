/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** utils
*/

#include <SFML/Graphics.h>
#include "lib/str.h"
#include "components/components.h"
#include "parsing/utils.h"

void clean_char(char *data, int size)
{
    for (int i = 0; i < size; i++) {
        data[i] = '\0';
    }
}

static void manage_data_extend(char *nb, parsing_t *element)
{
    if (my_strcmp(element->types, "anim_rect") == 0)
        get_anim_rect(nb, element);
    if (my_strcmp(element->types, "anim_index") == 0)
        get_anim_index(nb, element);
    if (my_strcmp(element->types, "anim_max") == 0)
        get_anim_max(nb, element);
    if (my_strcmp(element->types, "anim_speed") == 0)
        get_anim_speed(nb, element);
}

static void manage_functions(char *nb, parsing_t *element)
{
    if (my_strcmp(element->types, "clicked") == 0)
        get_clicked(nb, element);
    if (my_strcmp(element->types, "hover") == 0)
        get_hover(nb, element);
    if (my_strcmp(element->types, "disabled") == 0)
        get_disabled(nb, element);
    if (my_strcmp(element->types, "moved") == 0)
        get_clicked(nb, element);
    if (my_strcmp(element->types, "pressed") == 0)
        get_pressed(nb, element);
    if (my_strcmp(element->types, "released") == 0)
        get_disabled(nb, element);
    if (my_strcmp(element->types, "next_to") == 0)
        get_next_to(nb, element);
}

static void manage_data(char *nb, parsing_t *element, app_t *app)
{
    if (my_strcmp(element->types, "position") == 0)
        get_position(nb, element, app);
    if (my_strcmp(element->types, "size") == 0)
        get_size(nb, element, app);
    if (my_strcmp(element->types, "rect") == 0)
        get_rect(nb, element);
    if (my_strcmp(element->types, "style") == 0)
        get_style(nb, element);
    if (my_strcmp(element->types, "type") == 0)
        get_type(nb, element);
    if (my_strcmp(element->types, "c_size") == 0)
        get_c_size(nb, element);
    if (my_strcmp(element->types, "id") == 0)
        get_id(nb, element);
    if (my_strcmp(element->types, "radius") == 0)
        get_radius(nb, element);
    manage_functions(nb, element);
    manage_data_extend(nb, element);
}

void manage_number(char *file, parsing_t *element, app_t *app, int *index)
{
    char nb[6];
    int nb_index = 0;

    clean_char(nb, 6);
    *index += 1;
    do {
        *index += 1;
        if (file[*index] == ' ' || file[*index] == '\n') {
            manage_data(nb, element, app);
            clean_char(nb, 6);
            nb_index = 0;
        } else {
            nb[nb_index] = file[*index];
            nb_index++;
        }
    } while (file[*index] != '\n');
}
