/*
** init_scene.c for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Mon May 26 11:26:03 2014 archer
** Last update Sun Jun  8 22:30:31 2014 lagier_e
*/

#include	<stdlib.h>
#include	<string.h>
#include	"raytracer.h"
#include	"parser.h"

static void	init_tabs(char **elems, double *values)
{
  elems[0] = "size_x";
  elems[1] = "size_y";
  elems[2] = "anti-aliasing";
  elems[3] = "ambient_light";
  values[0] = 800;
  values[1] = 800;
  values[2] = 1;
  values[3] = 0;
}

int		init_scene(t_all *all, t_list *list, UNUSED FILE *fd)
{
  char		*elems[4];
  double	values[4];
  double	nb;
  int		i;

  init_tabs(elems, values);
  if ((list = list->next) == NULL)
    return (-1);
  while (list != NULL && list->type != END)
    {
      i = -1;
      while (++i < 4 && strcmp(elems[i], list->lexeme) != 0);
      if (i == 4 || (list = list->next) == NULL ||
	  (list = list->next) == NULL || (list = list->next) == NULL)
	return (-1);
      if ((nb = atof(list->lexeme)) > 0)
	values[i] = nb;
      if ((list = list->next) == NULL || (list = list->next) == NULL)
	return (-1);
    }
  all->global.size_x = 1000;
  all->global.size_y = 1000;
  all->global.anti_aliasing = values[2];
  all->global.ambient_light = values[3];
  return (0);
}
