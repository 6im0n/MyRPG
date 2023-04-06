/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** output
*/

#ifndef OUTPUT_H_
    #define OUTPUT_H_

    #include <unistd.h>

/**
 * @brief Print given str on specified output.
 * @param str String to print
 * @param output Output on which print (ex: 1 for std or 2 for err)
 * @returns Number of printed chars or -1 if failed
 */
ssize_t my_putstr(char const *str, int output);

/**
 * @brief Print given nb on std output
 * @param nb Number to print
 */
int my_put_nbr(int nb);

/**
 * @brief Mini printf fonction
 * @param format text and flags
 * @param ... variables to display
 * @return int nb of char printed
 */
int my_printf(const char *format, ...);

#endif /* !OUTPUT_H_ */
