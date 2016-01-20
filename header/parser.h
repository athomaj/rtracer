/*
** parser.h for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Fri May 30 11:42:03 2014 archer
** Last update Sun Jun  8 21:38:16 2014 maillot
*/

#ifndef PARSER_H_
# define PARSER_H_

#include		<stdio.h>
#include		"raytracer.h"

# define OPEN		"Open failed"
# define CLOSE		"Close failed"
# define SYNTAX_ERROR	"Syntax error"

# define NB_MAJ_OPT	5
# define NB_LEX		5
# define NB_FST_FCT	6
# define NB_OBJ		4

# define START		0
# define EQUAL		1
# define INHIB		2
# define END		3
# define VALUE		4
# define ELEM		5
# define TITLE		6

# define OBJECT		0
# define SPOT		1
# define CLASS		2

char			*get_next_line_custom(FILE *);
int			error_function(char *, int, int);
int			init_parsing(t_all *, char **);
int			check_syntax(t_list *);
int			send_to_fct(t_all *, t_list *, FILE *, int *);
int			parsing(t_all *, char *);
int			lexer(t_list **, char *);

int			take_infos_object(t_class *, t_object *,
					  t_list *, t_class **);
int			take_infos_class(t_class *, t_list *, t_class **);
int			take_infos_spot(t_class *, t_spot *,
					t_list *, t_class **);
int			create_elem(t_all *, t_list *, FILE *, int *);
int			fill_values(t_list *, char **, double *, t_coord *);
int			create_eye(t_all *, t_list *, FILE *, int *);
int			do_include(t_all *, t_list *, FILE *, int *);
int			init_scene(t_all *, t_list *, FILE *);
int			the_end(t_list *, char *);

void			add_values_to_list(t_all *, t_coord *,
					   double *, int);
void			init_values(double *, t_coord *, t_class *);
void			init_elems(char **);

int			add_object_to_list(t_object **);
int			add_class_to_list(t_class **);
int			add_spot_to_list(t_spot **);

void			free_things(t_list *, char *);
int			see_lists(t_all *);

int			core_start(t_all *);

#endif	/* !PARSER_H_ */
