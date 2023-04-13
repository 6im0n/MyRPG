/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** utils
*/

#ifndef BUTTONS_UTILS_H_
    #define BUTTONS_UTILS_H_

    #include "types/type.h"
    #include "components/components.h"

void get_size(char *nb, parsing_t *element, app_t *app);
void get_rect(char *nb, parsing_t *element);
void get_style(char *nb, parsing_t *element);
void get_type(char *nb, parsing_t *element);
void get_c_size(char *nb, parsing_t *element);
void get_clicked(char *nb, parsing_t *element);
void get_hover(char *nb, parsing_t *element);
void get_disabled(char *nb, parsing_t *element);
void get_anim_rect(char *nb, parsing_t *element);
void get_anim_index(char *nb, parsing_t *element);
void get_anim_max(char *nb, parsing_t *element);
void get_anim_speed(char *nb, parsing_t *element);
void get_moved(char *nb, parsing_t *element);
void get_released(char *nb, parsing_t *element);
void get_pressed(char *nb, parsing_t *element);
void get_position(char *nb, parsing_t *element);
void get_position(char *nb, parsing_t *element);
void get_id(char *nb, parsing_t *element);
void get_next_to(char *nb, parsing_t *element);
void get_radius(char *nb, parsing_t *element);

void clean_char(char *data, int size);
void manage_number(char *file, parsing_t *element, int *index);

#endif /* BUTTONS_UTILS_H_ */
