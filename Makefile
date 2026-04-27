##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter project
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SFMLFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window
DEBUGFLAGS = -g3 -ggdb
PATH_SRC = src/
PATH_UTILS = utils/
PATH_PRINTF = utils/printf/
SRC = $(PATH_SRC)window.c\
	$(PATH_SRC)duck.c\
	$(PATH_SRC)player.c\
	$(PATH_SRC)main.c\
	$(PATH_UTILS)my_strcmp.c\
	$(PATH_UTILS)my_int_to_str.c\
	$(PATH_PRINTF)my_printf.c\
	$(PATH_PRINTF)flag_c.c\
	$(PATH_PRINTF)flag_d.c\
	$(PATH_PRINTF)flag_s.c\
	$(PATH_PRINTF)flag_percent.c\
	$(PATH_PRINTF)my_putchar.c\
	$(PATH_PRINTF)my_put_nbr.c\
	$(PATH_PRINTF)my_putstr.c\
	$(PATH_PRINTF)my_strlen.c
OBJ = $(SRC:.c=.o)
NAME = my_hunter

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(SFMLFLAGS) -o $(NAME)

debug: fclean $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUGFLAGS) $(SFMLFLAGS) -o $(NAME)
# gdb $(NAME) | run | bt

clean:
	rm -f $(PATH_SRC)*.o
	rm -f $(PATH_UTILS)*.o
	rm -f $(PATH_PRINTF)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
