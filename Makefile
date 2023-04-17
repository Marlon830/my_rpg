##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

SRC = $(shell find src -name "*.c")
CFLAGS = -W -Wextra -Wall
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
CPPFLAGS = -Iinclude
TARGET = my_rpg
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
