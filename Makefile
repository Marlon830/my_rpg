##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

SRC = src/main.c \
	  src/scene/scene_create.c \
	  src/scene/scene_create_bis.c \
	  src/scene/scene_draw.c \
	  src/scene/scene_draw_bis.c \
	  src/scene/scene_init.c \
	  src/scene/colliders_init.c \
	  src/scene/scene_event.c \
	  src/scene/scene_destroy.c \
	  src/scene/move_camera.c \
	  src/scene/inventory_create.c \
	  src/scene/inventory_create2.c \
	  src/dialogue/create_dialogue.c \
	  src/dialogue/display_dialogue.c \
	  src/dialogue/get_info_dialogue.c \
	  src/dialogue/changes_dialogue.c \
	  src/updates/update_scene.c \
	  src/updates/update_inventory.c \
	  src/updates/update_inventory2.c \
	  src/utils/string.c \
	  src/utils/string_bis.c \
	  src/utils/list.c \
	  src/utils/inventory_list.c \
	  src/utils/inventory_list2.c \
	  src/utils/inventory_list3.c \
	  src/utils/button_manager.c \
	  src/menu/menu_init.c \
	  src/menu/menu_event.c \
	  src/menu/menu_draw.c \
	  src/menu/button_clicked.c \

CFLAGS = -Wextra -Wall

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CPPFLAGS = -I./include -I./csfml_engine/include

SRC = $(shell find src -name "*.c")

OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

coding_style : fclean
	~/Documents/coding-style-checker/coding-style.sh . ..
	cat ../coding-style-reports.log

re : fclean all
