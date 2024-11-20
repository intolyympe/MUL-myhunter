##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter project
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SFMLFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window
PATH_SRC = src/
SRC = $(PATH_SRC)test.c

OJB = $(SRC:.c=.o)
NAME = my_hunter

all:
	$(CC) $(SRC) $(CFLAGS) $(SFMLFLAGS) -o $(NAME)

clean:
	rm -f $(PATH_SRC)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all