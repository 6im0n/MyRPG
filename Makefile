##
## EPITECH PROJECT, 2023
## B-MUL-200-NAN-2-1-myrpg-thomas.quintin
## File description:
## Makefile
##


_SRC =			main.c \
				\
				app/app.c \
				app/event.c \
				app/rendering.c \
				app/component.c \
				\
				ressources/ressources.c \
				ressources/textures.c \
				ressources/sounds.c \
				\
				components/misc/render.c \
				components/start_menu/get.c \
				\
				types/app/app.c \
				types/app/icon.c \
				types/app/mouse.c \
				types/app/state.c \
				types/renderer/objects.c \

SRCDIR = 		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ = 			$(SRC:.c=.o)

INC = 			-I./include -I. -I./lib
LIBS =			./libcommon.a

CFLAGS 	=		-W -Wall -Wextra -Werror -g

MODULES = -l csfml-graphics -l csfml-audio -l csfml-system -lm

NAME = 			my_rpg

all: 			$(NAME) clean

$(NAME):
				@make -C lib -s
				@gcc -o $(NAME) $(SRC) $(INC) $(LIBS) $(MODULES) $(CFLAGS)
				@$(MAKE) clean -s

clean:
				@rm -f $(OBJ)
				@make -C lib fclean -s

fclean: 		clean
				@rm -f $(NAME)
				@make -C lib fclean -s

re: 			fclean all

color = /bin/echo -e "\x1b[33m $1\x1b[0m"

run: re
	clear
	@$(call color,"🚀:")
	@./$(NAME) $(ARGS)
