##
## EPITECH PROJECT, 2022
## test_map
## File description:
## Makefile
##

TARGET = my_rpg

CFLAGS = -Wextra -Wall

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CPPFLAGS = -I./include -I./csfml_engine/include

SRC = $(shell find src -name "*.c")

OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LDFLAGS) -g3

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

coding_style : fclean
	~/Documents/coding-style-checker/coding-style.sh . ..
	cat ../coding-style-reports.log

re : fclean all
