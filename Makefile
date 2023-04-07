##
## EPITECH PROJECT, 2022
## test_map
## File description:
## Makefile
##

TARGET = my_rpg

CFLAGS = -Wextra -Wall

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CPPFLAGS = -I./include -I./csfml_engine/include

SRC = ./src/main.c \
	  ./src/graphic/graphic_create.c \
	  ./src/graphic/graphic_draw.c \
	  ./src/graphic/graphic_init.c \
	  ./src/graphic/colliders_init.c \
	  ./src/graphic/graphic_event.c \
	  ./src/graphic/graphic_destroy.c \
	  ./src/graphic/move_camera.c \
	  ./src/utils/string.c \
	  ./src/utils/string_bis.c \
	  ./src/utils/list.c \

OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LDFLAGS) -g3

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)

re : fclean all
