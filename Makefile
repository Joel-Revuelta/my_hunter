##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

SRC	= 	src/main.c				\
		src/csfml_objects.c		\
		src/events.c			\
		src/init_game.c			\
		src/display.c			\
		src/destroyer.c			\
		src/hunter.c			\
		src/dragons.c			\
		src/pokeballs.c			\
		src/handlers.c

NAME = my_hunter

CC = gcc

CFLAGS = -g3 -w -Wall -Wextra -Werror -I include/ -L lib/ -lmy
CSFML =  -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

all: 	$(NAME)

$(NAME): dolib $(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(CSFML)

dolib:
	cd lib; make

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	cd lib; make clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	cd lib; make fclean

re:	fclean all
	make clean
