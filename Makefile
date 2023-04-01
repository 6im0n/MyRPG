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
				ressources/fonts.c \
				\
				components/free.c \
				components/misc/render.c \
				components/misc/effect_botton.c \
				components/misc/events_dispatch.c \
				components/misc/events_handlers.c \
				components/misc/state.c \
				components/new/set.c \
				components/new/type.c \
				components/new/size.c \
				components/new/text.c \
				\
				components/menu/start/get.c \
				components/menu/start/menu.c \
				components/menu/start/bouton.c \
				components/menu/help/get.c \
				components/menu/help/menu.c \
				components/inventory/get.c \
				components/inventory/menu.c \
				components/inventory/object.c \
				components/inventory/object_select.c \
				components/setting/get.c \
				components/setting/menu.c \
				components/setting/sound.c \
				\
				events/setting/open.c \
				events/setting/selector.c \
				events/menu/start/bouton.c \
				events/menu/help/bouton.c \
				events/inventory/select.c \
				\
				types/app/app.c \
				types/app/icon.c \
				types/app/mouse.c \
				types/app/state.c \
				types/renderer/objects.c \
				\
				types/list/component/list.c \
				types/list/component/append.c \

SRCDIR = 		src/

SRC =			$(addprefix $(SRCDIR), $(_SRC))
OBJ = 			$(SRC:.c=.o)

INC = 			-I./include -I. -I./lib
LIBS =			./libcommon.a

CFLAGS 	=		-W -Wall -Wextra -Werror -g

MODULES = -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm

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
