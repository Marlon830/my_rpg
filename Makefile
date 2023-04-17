##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

TARGET = ./my_rpg
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
