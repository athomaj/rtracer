/*
** main.c for raytracer in /home/archer_j/rendu/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Wed May  7 10:58:21 2014 archer
** Last update Sun Jun  8 16:13:34 2014 borel_d
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"raytracer.h"
#include	"parser.h"

void		free_things(t_list *list, char *str)
{
  t_list	*tmp;

  free(str);
  while (list != NULL)
    {
      tmp = list->next;
      free(list->lexeme);
      free(list);
      list = tmp;
    }
}

static void	init_struct(t_all *all)
{
  all->objects = NULL;
  all->class = NULL;
  all->spots = NULL;
  all->files = NULL;
  all->global.anti_aliasing = 1;
  all->global.size_x = 800;
  all->global.size_y = 600;
}

int		main(int ac, char **av)
{
  t_all		infos;

  if (ac != 2)
    {
      fprintf(stderr, "\n\t%s\n", USAGE);
      return (-1);
    }
  init_struct(&infos);
  if (init_parsing(&infos, av) == -1)
    return (-1);
  if (see_lists(&infos) < 0)
    {
      fprintf(stderr, "\nfail on printf\n");
      return (-1);
    }
  core_start(&infos);
  return (0);
}
