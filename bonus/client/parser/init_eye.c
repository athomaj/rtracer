/*
** init_eye.c for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp/parser
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Tue Jun  3 10:26:25 2014 archer
** Last update Sun Jun  8 15:39:36 2014 borel_d
*/

#include	<string.h>
#include	<stdlib.h>
#include	"raytracer.h"
#include	"parser.h"

static int	init_coords(t_list *list, t_coord *coord)
{
  double	*values[3];
  char		*indexes;
  char		*lexeme;
  int		i;

  indexes = "xyz";
  values[0] = &coord->x;
  values[1] = &coord->y;
  values[2] = &coord->z;
  while (list != NULL && list->type != END)
    {
      lexeme = list->lexeme;
      i = -1;
      while (++i < 3 && (lexeme[0] != indexes[i] || lexeme[1] != 0));
      if (i < 3)
	*values[i] = atof((list = list->next->next->next)->lexeme);
      else
	return (-1);
      list = list->next->next;
    }
  return (0);
}

int		create_eye(t_all *all, t_list *list, FILE *fd, int *err)
{
  char		*str;
  int		i;

  list = NULL;
  i = 0;
  while ((str = get_next_line_custom(fd)) != NULL && ++ i > 0 &&
	 lexer(&list, str) != -1 && the_end(list, "EYE") == -1)
    {
      if ((strcmp("pos", (list = list->next)->lexeme) == 0 &&
	   init_coords(list->next, &all->eye.pos) == -1) ||
	  (strcmp("rot", list->lexeme) == 0 &&
	   init_coords(list->next, &all->eye.rot) == -1) ||
	  (strcmp("rot", list->lexeme) != 0 &&
	   strcmp("pos", list->lexeme) != 0))
	*err = -1;
      free_things(list, str);
      if (*err == -1)
	return (-1);
      list = NULL;
    }
  if (the_end(list, "EYE") == 0)
    return (i);
  *err = -1;
  return (i);
}
