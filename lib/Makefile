##
## Makefile for Makefile in /home/maillo_f/rendu/Piscine-C-Jour_11
## 
## Made by maillot
## Login   <maillo_f@epitech.net>
## 
## Started on  Mon Oct 21 09:55:48 2013 maillot
## Last update Mon May 26 15:43:50 2014 archer
##

SRC		=			\
		example.c		\

CFLAGS		= -W -Wall -Werror -Wextra -ansi -pedantic -std=gnu99

CFLAGS		+= -g3

RM		= rm -f

NAME		= libmy.a

OBJ		= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
