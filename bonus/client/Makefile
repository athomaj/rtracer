##
## Makefile for raytracer in /home/archer_j/rendu/raytracer_tmp
## 
## Made by archer
## Login   <archer_j@epitech.net>
## 
## Started on  Wed May  7 11:09:37 2014 archer
## Last update Sun Jun  8 21:08:45 2014 lagier_e
##

NAME		= rt

SRC_PARSER	=					\
		parser/get_next_line_custom.c		\
		parser/add_values_to_list.c		\
		parser/error_function.c			\
		parser/init_parsing.c			\
		parser/print_things.c			\
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
		parser/main.c

SRC_CORE	=					\
		transformation/transformation.c		\
		transformation/init_rotate.c		\
		core/init_core_functions.c		\
		core/init_intersection.c		\
		transformation/rotate.c			\
		core/check_function.c			\
		shadowlight/fill_light.c		\
		shadowlight/reflection.c		\
		shadowlight/brightness.c		\
		shadowlight/ray_travel.c		\
		shadowlight/light.c			\
		core/intersection.c			\
		core/thread_core.c			\
		core/core_mlx.c				\
		core/limit_next_init.c			\
		core/limit_init.c			\
		core/limit.c				\
		core/core.c				\
		core/start.c				\
		core/network_func.c			\

OBJ		= $(SRC_PARSER:.c=.o)

OBJ_CORE	= $(SRC_CORE:.c=.o)

TMP		= $(SRC_PARSER:.c=.c~)

TMP_CORE	= $(SRC_core:.c=.c~)

CC		= gcc -Iheader/

LIB		= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm -lpthread

RM		= rm -f

CFLAGS		= -W -Wextra -Wall -Werror -ansi -pedantic -std=gnu99 -g3


all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_CORE)
		$(CC) $(OBJ) $(OBJ_CORE) $(LIB) -o $(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_CORE)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

norm:		re
		$(RM) $(OBJ) $(OBJ_CORE) $(TMP) $(TMP_CORE)

.PHONY:		all clean fclean norm re
