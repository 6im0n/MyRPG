##
## EPITECH PROJECT, 2023
## lib
## File description:
## Makefile
##

_SRC =			output/my_printf.c \
				output/output.c \
				\
				str/strlen.c \
				str/strcmp.c \
				str/strtoint.c \
				str/strcpy.c \
				str/strdup.c \
				str/strcat.c \
				\
				tools/my_nbrlen.c \
				tools/my_converse.c \

SRCDIR =		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ =			$(SRC:.c=.o)

INC =			-I../include -I.
CFLAGS =		-W -Wall -Wextra -Werror -g

NAME = 			libcommon.a

.SILENT:		all clean $(NAME) $(OBJ)

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@ar rc $(NAME) $(OBJ)
				$(MAKE) clean -s
				@cp $(NAME) ../$(NAME)

%.o: %.c
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@rm -f $(OBJ)

fclean: 		clean
				@rm -rf $(NAME) ../$(NAME)
