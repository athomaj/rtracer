##
## Makefile for Makefile in /home/lagier_e/rendu
##
## Made by lagier_e
## Login   <lagier_e@epitech.net>
##
## Started on  Fri Mar 21 12:05:23 2014 lagier_e
## Last update Sun Jun  8 16:23:16 2014 lagier_e
##

NAME=	server

SRC=	main.c		\
	libx_func.c	\
	network_func.c	\
	usefull_func.c	\

OBJ=	$(SRC:.c=.o)

CFLAGS=	-Wall -Werror -Wextra -ansi -pedantic -std=gnu99

all:	$(NAME)

$(NAME):$(OBJ)
	cc -o $(NAME) $(OBJ) -lpthread -lmlx -lXext -lX11

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

.PHONY:	all clean clean fclean
