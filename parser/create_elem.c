/*
** create_elem.c for raytracer in /home/archer_j/rendu/tmp/parser_test
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Fri Jun  6 10:14:12 2014 archer
** Last update Sun Jun  8 15:23:14 2014 borel_d
*/

#include	<string.h>
#include	<stdlib.h>
#include	"raytracer.h"
#include	"parser.h"

static int	find_type(t_all *all, t_list *list)
{
  if (strcmp(list->lexeme, "OBJECT") == 0)
    {
      if (add_object_to_list(&all->objects) == -1)
	return (-1);
      return (OBJECT);
    }
  else if (strcmp(list->lexeme, "SPOT") == 0)
    {
      if (add_spot_to_list(&all->spots) == -1)
	return (-1);
      return (SPOT);
    }
  return ((add_class_to_list(&all->class) == -1) ? -1 : CLASS);
}

static int	find_class(t_all *all, t_list *list, t_class **class, int type)
{
  *class = NULL;
  if (type == OBJECT)
    return (take_infos_object(all->class, all->objects, list->next, class));
  else if (type == SPOT)
    return (take_infos_spot(all->class, all->spots, list->next, class));
  return (take_infos_class(all->class, list->next, class));
}

int		the_end(t_list *list, char *str)
{
  if (list == NULL)
    return (-1);
  if (list->type != START || (list = list->next) == NULL ||
      list->type != END || (list = list->next) == NULL ||
      list->type != TITLE || (str != NULL && strcmp(str, list->lexeme) != 0) ||
      (list = list->next) == NULL || list->type != END ||
      (list = list->next) != NULL)
    return (-1);
  return (0);
}

int		pars_values(double *values, t_coord *coord,
			    FILE *fd, int *err)
{
  t_list	*list;
  char		*elems[12];
  char		*str;
  int		i;

  init_elems(elems);
  list = NULL;
  i = 0;
  while ((str = get_next_line_custom(fd)) != NULL && ++i > 0 &&
	 lexer(&list, str) != -1 && the_end(list, NULL) != 0 &&
	 check_syntax(list) == 0)
    {
      if (list != NULL && fill_values(list->next, elems, values, coord) == -1)
	{
	  *err = -1;
	  return (i);
	}
      free_things(list, str);
      list = NULL;
    }
  if (the_end(list, NULL) != 0)
    *err = -1;
  return (i);
}

int		create_elem(t_all *all, t_list *list, FILE *fd, int *err)
{
  t_coord	coords[4];
  t_class	*tmp;
  double	values[11];
  int		type;
  int		l;

  if ((type = find_type(all, list)) == -1)
    {
      *err = -1;
      return (0);
    }
  find_class(all, list, &tmp, type);
  init_values(values, coords, tmp);
  l = pars_values(values, coords, fd, err);
  if (*err != -1)
    add_values_to_list(all, coords, values, type);
  return (l);
}
