/*
** add_to_list.c for raytracer in /home/archer_j/rendu/tmp/parser_test
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Fri Jun  6 10:16:00 2014 archer
** Last update Sat Jun  7 10:00:46 2014 archer
*/

#include	<stdlib.h>
#include	"raytracer.h"

int		add_object_to_list(t_object **objects)
{
  t_object	*elem;

  if ((elem = malloc(sizeof(t_object))) == NULL)
    return (-1);
  elem->next = *objects;
  *objects = elem;
  return (0);
}

int		add_class_to_list(t_class **class)
{
  t_class	*elem;

  if ((elem = malloc(sizeof(t_class))) == NULL)
    return (-1);
  elem->next = *class;
  elem->object_elem.next = NULL;
  elem->spot_elem.next = NULL;
  *class = elem;
  return (0);
}

int		add_spot_to_list(t_spot **spots)
{
  t_spot	*elem;

  if ((elem = malloc(sizeof(t_spot))) == NULL)
    return (-1);
  elem->next = *spots;
  *spots = elem;
  return (0);
}
