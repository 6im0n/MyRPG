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
				app/render.c \
				app/event_game.c \
				app/event_game_player.c \
				app/rendering.c \
				app/component.c \
				app/component_menu.c \
				app/popup.c \
				app/player.c \
				\
				ressources/ressources.c \
				ressources/textures.c \
				ressources/sounds.c \
				ressources/fonts.c \
				\
				components/free.c \
				components/misc/render.c \
				components/misc/render_background.c \
				components/misc/effect_botton.c \
				components/misc/events_dispatch.c \
				components/misc/events_handlers.c \
				components/misc/events_handlers_keys.c \
				components/misc/events_default.c \
				components/misc/events_animation.c \
				components/misc/player_animation.c \
				components/misc/mobs_animation.c \
				components/misc/state.c \
				components/items/get.c \
				components/items/new.c \
				components/items/sword.c \
				components/items/knif.c \
				components/items/hammer.c \
				components/items/axe.c \
				components/items/spear.c \
				components/new/set.c \
				components/new/type.c \
				components/new/size.c \
				components/new/text.c \
				components/new/animation.c \
				components/new/mob.c \
				components/cursor.c \
				\
				components/player/player.c \
				components/player/inventory.c \
				\
				components/mobs/mobs.c \
				\
				components/game/get.c \
				components/game/menu.c \
				components/game/add_mobs.c \
				\
				components/new_game/get.c \
				components/new_game/menu.c \
				components/menu/start/get.c \
				components/menu/start/menu.c \
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
				components/inventory/levels/menu.c \
				components/inventory/quests/menu.c \
				components/inventory/quests/prompt.c \
				components/setting/get.c \
				components/setting/menu.c \
				components/setting/sound.c \
				components/setting/bouton.c \
				components/setting/screen.c \
				components/view/manage.c \
				components/view/player.c \
				\
				events/help.c \
				events/cursor.c \
				events/setting.c \
				events/animation.c \
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
				events/inventory/selector.c \
				events/levels/levels.c \
				events/game/player.c \
				events/game/collisions.c \
				events/game/dialog.c \
				events/game/lunch.c \
				events/game/select_character.c \
				\
				events/game/resume.c \
				events/game/resume_load.c \
        \
				events/game/mobs.c\
				events/game/mobs_action.c\
				\
				events/game/quests/main.c \
				\
				types/app/app.c \
				types/app/icon.c \
				types/app/mouse.c \
				types/app/state.c \
				types/app/save.c \
				types/app/load.c \
				types/app/loader.c \
				\
				types/list/component/list.c \
				types/list/component/append.c \
				types/list/quest/list.c \
				types/list/quest/append.c \
				types/list/player/list.c \
				types/list/player/append.c \
				types/list/mobs/list.c \
				types/list/mobs/append.c \
				types/list/mobs/node.c \
				types/list/pop_up/list.c \
				types/list/pop_up/append.c \
				\
				types/node/component/node.c \
				\
				parsing/parsing.c \
				parsing/function.c \
				parsing/animation.c \
				parsing/position.c \
				parsing/utils.c \
				parsing/size.c \
				parsing/type.c \
				parsing/functions.c \
				parsing/init.c \
				parsing/text.c \
				\
				utils/file.c \
				types/list/player/switch.c \
				types/list/player/remove.c \
				types/list/quest/remove.c \

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
