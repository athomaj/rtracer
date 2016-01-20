##
## Makefile for raytracer in /home/archer_j/rendu/raytracer_tmp
## 
## Made by archer
## Login   <archer_j@epitech.net>
## 
## Started on  Wed May  7 11:09:37 2014 archer
## Last update Sun Jun  8 21:58:04 2014 maillot
##

NAME		= rt

SRC_PARSER	=					\
		parser/get_next_line_custom.c		\
		parser/add_values_to_list.c		\
		parser/error_function.c			\
		parser/init_parsing.c			\
		parser/print_things.c                   \
		parser/fill_values.c			\
		parser/add_to_list.c			\
		parser/send_to_fct.c			\
		parser/create_elem.c			\
		parser/do_include.c			\
		parser/take_infos.c			\
		parser/init_scene.c			\
		parser/init_elems.c			\
		parser/init_eye.c			\
		parser/lexer.c				\
		parser/main.c				\

SRC_CORE	=					\
		core/check_function.c			\
		core/core.c				\
		core/core_mlx.c				\
		core/intersection.c			\
		core/init_core_functions.c		\
		core/init_intersection.c		\
		core/limit.c				\
		core/limit_init.c			\
		core/limit_next_init.c			\
		core/start.c				\
		core/thread_core.c			\
		shadowlight/reflection.c		\
		shadowlight/brightness.c		\
		shadowlight/ray_travel.c		\
		shadowlight/light.c			\
		transformation/init_rotate.c		\
		transformation/rotate.c			\
		transformation/transformation.c		\



OBJ		= $(SRC_PARSER:.c=.o)

OBJ_CORE	= $(SRC_CORE:.c=.o)

CC		= gcc -Iheader/ -I./minilibx

LIB		= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm -lpthread -L./minilibx

RM		= rm -f

CFLAGS		= -W -Wextra -Wall -Werror -ansi -pedantic -std=gnu99


all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_CORE)
	$(CC) $(OBJ) $(OBJ_CORE) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_CORE)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
