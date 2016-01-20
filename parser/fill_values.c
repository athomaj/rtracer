/*
** fill_values.c for raytracer in /home/archer_j/rendu/tmp/parser_test
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Fri Jun  6 16:35:44 2014 archer
** Last update Sun Jun  8 15:18:13 2014 borel_d
*/

#include	<stdlib.h>
#include	<string.h>
#include	"raytracer.h"
#include	"parser.h"

static int	check_single_elem(t_list *list)
{
  if (list->type != TITLE || (list = list->next) == NULL ||
      list->type != VALUE || strcmp(list->lexeme, "value") != 0 ||
      (list = list->next) == NULL || list->type != EQUAL ||
      (list = list->next) == NULL || list->type != INHIB ||
      (list = list->next) == NULL || list->type != ELEM ||
      (list = list->next) == NULL || list->type != INHIB ||
      (list = list->next) == NULL || list->type != END ||
      (list = list->next) != NULL)
    return (-1);
  return (0);
}

static int	init_color(t_list *list, double *values)
{
  char		*str;
  int		i;

  str = "rgb";
  while (list != NULL && list->type != END)
    {
      i = -1;
      while (++i < 3 && (str[i] != list->lexeme[0] || list->lexeme[1] != 0));
      if (i == 3)
	return (-1);
      values[i + 8] = atof((list = list->next->next->next)->lexeme);
      list = list->next->next;
    }
  return (0);
}

static int	init_coords_values(t_list *list, t_coord *coords, int i)
{
  double	values[3];
  char		*str;
  int		a;

  a = i - 7;
  str = "xyz";
  while (list != NULL && list->type != END)
    {
      i = -1;
      while (++i < 3 && (str[i] != list->lexeme[0] || list->lexeme[1] != 0));
      if (i == 3)
	return (-1);
      values[i] = atof((list = list->next->next->next)->lexeme);
      list = list->next->next;
    }
  coords[a].x = values[0];
  coords[a].y = values[1];
  coords[a].z = values[2];
  return (0);
}

int		fill_values(t_list *list, char **elems,
			    double *values, t_coord *coords)
{
  int		i;

  i = -1;
  while (++i < 12 && strcmp(list->lexeme, elems[i]) != 0);
  if (i < 7 || i == 12)
    {
      if (check_single_elem(list) == -1)
  	return (-1);
      values[(i < 7 ? i : 7)] = atof(list->next->next->next->next->lexeme);
      return (0);
    }
  else if (i == 11)
    return ((init_color(list->next, values) == -1) ? -1 : 0);
  return (init_coords_values(list->next, coords, i));
}
