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
				app/component_menu.c \
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
				components/misc/events_default.c \
				components/misc/events_annimation.c \
				components/misc/state.c \
				components/items/get.c \
				components/items/new.c \
				components/new/set.c \
				components/new/type.c \
				components/new/size.c \
				components/new/text.c \
				components/new/annimation.c \
				components/cursor.c \
				\
				components/player/player.c \
				components/player/inventory.c \
				\
				components/menu/start/get.c \
				components/menu/start/menu.c \
				components/menu/start/bouton.c \
				components/menu/start/annimation.c \
				components/menu/load/get.c \
				components/menu/load/menu.c \
				components/menu/load/bouton.c \
				components/menu/help/get.c \
				components/menu/help/menu.c \
				components/menu/help/move.c \
				components/menu/help/command.c \
				components/inventory/get.c \
				components/inventory/menu.c \
				components/inventory/object.c \
				components/inventory/object_select.c \
				components/setting/get.c \
				components/setting/menu.c \
				components/setting/sound.c \
				components/setting/bouton.c \
				components/setting/screen.c \
				\
				events/help.c \
				events/cursor.c \
				events/setting.c \
				events/annimation.c \
				\
				events/setting/open.c \
				events/setting/screen.c \
				events/setting/volume.c \
				events/setting/framerate.c \
				events/setting/hover.c \
				events/menu/start/bouton.c \
				events/menu/help/bouton.c \
				events/menu/help/keypress.c \
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
				types/list/player/list.c \
				types/list/player/append.c \

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
