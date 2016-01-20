/*
** take_infos.c for raytracer in /home/archer_j/rendu/tmp/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Thu Jun  5 14:54:25 2014 archer
** Last update Sun Jun  8 14:55:51 2014 borel_d
*/

#include	<stdlib.h>
#include	<string.h>
#include	"raytracer.h"
#include	"parser.h"

static void	search_class(t_class *class, t_class **tmp, char *name)
{
  while (class != NULL)
    {
      if (strcmp(class->name, name) == 0)
	*tmp = class;
      class = class->next;
    }
}

static int	retrieve_type(char *str)
{
  char		*elems[NB_OBJ];
  int		i;

  i = -1;
  elems[SPHERE] = "sphere";
  elems[CONE] = "cone";
  elems[PLAN] = "plan";
  elems[CYLINDRE] = "cylindre";
  while (++i < NB_OBJ && strcmp(str, elems[i]) != 0);
  return ((i == NB_OBJ) ? -1 : i);
}

int		take_infos_object(t_class *class, t_object *object,
				  t_list *list, t_class **tmp)
{
  object->type = 0;
  object->normale = 1;
  while (list != NULL && list->type != END)
    {
      if (strcmp("class", list->lexeme) == 0)
	search_class(class, tmp, (list = list->next->next->next)->lexeme);
      else if (strcmp("type", list->lexeme) == 0)
	object->type = retrieve_type((list = list->next->next->next)->lexeme);
      else if (strcmp("normale", list->lexeme) == 0)
	object->normale = atoi((list = list->next->next->next)->lexeme);
      else
	return (-1);
      list = list->next->next;
    }
  return ((object->type == -1) ? -1 : 0);
}

int		take_infos_spot(t_class *class, UNUSED t_spot *spot,
				t_list *list, t_class **tmp)
{
  while (list != NULL && list->type != END)
    {
      if (strcmp("class", list->lexeme) == 0)
	search_class(class, tmp, (list = list->next->next->next)->lexeme);
      list = list->next->next;
    }
  return (0);
}

int		take_infos_class(t_class *class, t_list *list,
				 UNUSED t_class **tmp)
{
  while (list != NULL && list->type != END)
    {
      if (strcmp("id", list->lexeme) == 0 &&
	  (class->name =
	   strdup((list = list->next->next->next)->lexeme)) == NULL)
	return (-1);
      else if (strcmp("id", list->lexeme) != 0)
	return (-1);
      list = list->next->next;
    }
  return (0);
}
