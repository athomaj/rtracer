/*
** add_values_to_list.c for raytracer in /home/archer_j/rendu/tmp/parser_test
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Sat Jun  7 09:11:53 2014 archer
** Last update Sat Jun  7 09:28:12 2014 archer
*/

#include	"raytracer.h"
#include	"parser.h"

void		add_values_to_object(t_object *object, t_coord *coords,
				     double *values)
{
  object->pos = coords[0];
  object->rot = coords[1];
  object->limits_inf = coords[2];
  object->limits_sup = coords[3];
  object->color.r = values[8];
  object->color.g = values[9];
  object->color.b = values[10];
  object->transparency = values[3];
  object->distortion = values[4];
  object->brightness = values[5];
  object->reflexion = values[6];
  object->infos = values[7];
}

void		add_values_to_spot(t_spot *spot, t_coord *coords,
				   double *values)
{
  spot->pos = coords[0];
  spot->color.r = values[8];
  spot->color.g = values[9];
  spot->color.b = values[10];
  spot->orientation = values[0];
  spot->intensity = values[1];
  spot->radius = values[2];
}

void		add_values_to_list(t_all *all, t_coord *coords,
				   double *values, int type)
{
  if (type == OBJECT)
    add_values_to_object(all->objects, coords, values);
  else if (type == SPOT)
    add_values_to_spot(all->spots, coords, values);
  else
    {
      add_values_to_object(&all->class->object_elem, coords, values);
      add_values_to_spot(&all->class->spot_elem, coords, values);
    }
}
