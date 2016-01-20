/*
** send_to_fct.c for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Mon May 26 08:35:15 2014 archer
** Last update Sat Jun  7 09:23:07 2014 archer
*/

#include	<stdlib.h>
#include	<string.h>
#include	"raytracer.h"
#include	"parser.h"

static void	init_tabs(char **name, int (**fct)())
{
  name[0] = "INCLUDE";
  name[1] = "SCENE";
  name[2] = "OBJECT";
  name[3] = "SPOT";
  name[4] = "CLASS";
  name[5] = "EYE";
  fct[0] = &do_include;
  fct[1] = &init_scene;
  fct[2] = &create_elem;
  fct[3] = &create_elem;
  fct[4] = &create_elem;
  fct[5] = &create_eye;
}

static int	exec_fct(t_all *infos, t_list *list, FILE *fd, int *err)
{
  char		*name[NB_FST_FCT];
  int		(*fct[NB_FST_FCT])();
  int		i;

  if (list == NULL)
    return (0);
  init_tabs(name, fct);
  i = -1;
  while (++i < NB_FST_FCT)
    if (strcmp(name[i], list->next->lexeme) == 0)
      return (fct[i](infos, list->next, fd, err));
  return (-1);
}

int		check_syntax(t_list *list)
{
  if (list == NULL)
    return (0);
  if (strcmp(list->lexeme, "<") != 0 || (list = list->next) == NULL ||
      list->type != TITLE || (list = list->next) == NULL)
    return (-1);
  while (list != NULL && list->type != END)
    if (list->type != VALUE || (list = list->next) == NULL ||
	list->type != EQUAL || (list = list->next) == NULL ||
	list->type != INHIB || (list = list->next) == NULL ||
	list->type != ELEM || (list = list->next) == NULL ||
	list->type != INHIB || (list = list->next) == NULL)
      return (-1);
  if (list == NULL || list->type != END ||
      (strcmp(list->lexeme, "/") != 0 && strcmp(list->lexeme, "/>") != 0 &&
       strcmp(list->lexeme, ">") != 0) || (strcmp(list->lexeme, "/") == 0 &&
       (list->next == NULL || strcmp(list->next->lexeme, ">") != 0 ||
	list->next->next != NULL)) ||
      ((strcmp(list->lexeme, "/>") == 0 ||
	strcmp(list->lexeme, ">") == 0) && list->next != NULL))
    return (-1);
  return (0);
}

int		send_to_fct(t_all *infos, t_list *list, FILE *fd, int *err)
{
  if (check_syntax(list) == -1)
    {
      *err = -1;
      return (0);
    }
  return (exec_fct(infos, list, fd, err));
}
