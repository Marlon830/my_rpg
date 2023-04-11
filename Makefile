##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

SRC = src/main.c \
	  src/graphic/graphic_create.c \
	  src/graphic/graphic_draw.c \
	  src/graphic/graphic_init.c \
	  src/graphic/colliders_init.c \
	  src/graphic/graphic_event.c \
	  src/graphic/graphic_destroy.c \
	  src/graphic/move_camera.c \
	  src/graphic/inventory_create.c \
	  src/updates/update_scene_one.c \
	  src/updates/updates_all_scenes.c \
	  src/updates/update_inventory.c \
	  src/scene/scene_create.c \
	  src/scene/scene_draw.c \
	  src/scene/scene_init.c \
	  src/scene/colliders_init.c \
	  src/scene/scene_event.c \
	  src/scene/scene_destroy.c \
	  src/scene/move_camera.c \
	  src/updates/update_scene.c \
	  src/utils/string.c \
	  src/utils/string_bis.c \
	  src/utils/list.c
OBJ = $(SRC:.c=.o)
CFLAGS = -W -Wall -Wextra
CPPFLAGS = -Iinclude
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
TARGET = my_rpg

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) -g3

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
