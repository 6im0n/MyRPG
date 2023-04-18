/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** str
*/

#ifndef STR_H_
    #define STR_H_

    #include <unistd.h>
    #include <stdbool.h>

//==================================================
// STRING
//==================================================

/**
 * @brief Compute len of given string
 * @param str String of which get length
 * @returns Length of string
 */
size_t my_strlen(const char *str);

/**
 * @brief Compare 2 given strings
 * @param s1 First string
 * @param s2 Second string
 * @return Difference between 2 strings
 */
int my_strcmp(char const *s1, char const *s2);

/**
 * @brief Compare 2 given strings n
 * @param s1 First string
 * @param s2 Second string
 * @param size size
 * @return Difference between 2 strings
 */
int my_strncmp(char const *s1, char const *s2, int size);

/**
 * @brief Convert given string to int
 * @param str String to convert
 */
int my_strtoint(char const *str);

/**
 * @brief Copy char src to dest
 * @param dest char *
 * @param src char *
 * @return char* combined
 */
char *my_strcpy(char *dest, char const *src);

/**
 * @brief Copy n char src to dest
 * @param dest char*
 * @param src char *
 * @param index int index
 * @return char* combined
 */
char *my_strncpy(char *dest, char const *src, int index);

/**
 * @brief duplicate Data
 * @param src char* to duplicate
 * @return char* duplicated data
 */
char *my_strdup(char const *src);

/**
 * @brief fusion two strings
 * @param dest must containt enough space
 * @param src data
 */
void my_strcat(char *dest, const char *src);

#endif /* !STR_H_ */
