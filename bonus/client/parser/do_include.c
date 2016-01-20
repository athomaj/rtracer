/*
** do_include.c for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Mon May 26 09:42:10 2014 archer
** Last update Thu Jun  5 08:55:40 2014 archer
*/

#include	<string.h>
#include	"raytracer.h"
#include	"parser.h"

int		do_include(t_all *all, t_list *list, UNUSED FILE *fd, int *err)
{
  list = list->next;
  while (list != NULL && list->type != END)
    {
      if (strcmp(list->lexeme, "file") != 0 || (list = list->next) == NULL ||
	  (list = list->next) == NULL || (list = list->next) == NULL)
	{
	  *err = -1;
	  return (0);
	}
      parsing(all, list->lexeme);
      if ((list = list->next) == NULL || (list = list->next) == NULL)
	{
	  *err = -1;
	  return (0);
	}
    }
  return (0);
}
