/*
** print_things.c for print_things in /home/borel_d/Downloads/raytracer/raytracer_tmp/parser
** 
** Made by borel_d
** Login   <borel_d@epitech.net>
** 
** Started on  Sun Jun  8 15:49:09 2014 borel_d
** Last update Sun Jun  8 16:12:58 2014 borel_d
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"raytracer.h"
#include	"parser.h"

static int	print_spe_obj(t_object *object)
{
  char		*types[4];
  char		*spe[4];

  types[0] = "sphere";
  types[1] = "cone";
  types[2] = "plan";
  types[3] = "cylindre";
  spe[0] = "Radius";
  spe[1] = "None";
  spe[2] = "Angle";
  spe[3] = "Radius";
  if (printf("Reflexion = %f\n", object->reflexion) < 0)
    return (-1);
  if ((object->type != 2 &&
       printf("%s = %f\n", spe[object->type], object->infos) < 0) ||
      printf("Type = %s\n\n", types[object->type]) < 0)
    return (-1);
  return (0);
}

static int	print_object(t_object *objects)
{
  while (objects != NULL)
    {
      if (printf("Object pos : x = %f, y = %f, z = %f\n",
		 objects->pos.x, objects->pos.y, objects->pos.z) < 0 ||
	  printf("Object rot : x = %f, y = %f, z = %f\n",
		 objects->rot.x, objects->rot.y, objects->rot.z) < 0 ||
	  printf("Object limits_inf : x = %f, y = %f, z = %f\n",
		 objects->limits_inf.x, objects->limits_inf.y,
		 objects->limits_inf.z) < 0 ||
	  printf("Object limits_sup : x = %f, y = %f, z = %f\n",
		 objects->limits_sup.x, objects->limits_sup.y,
		 objects->limits_sup.z) < 0 ||
	  printf("Object color : r = %f, g = %f, b = %f\n",
		 objects->color.r, objects->color.g, objects->color.b) < 0 ||
	  printf("Transparency = %f\nDistortion = %f\nBrightness = %f\n",
		 objects->transparency, objects->distortion,
		 objects->brightness) < 0 ||
	  print_spe_obj(objects) < 0)
	return (-1);
      objects = objects->next;
    }
  return (0);
}

static int	print_global(t_all *infos)
{
  if (printf("\nsize_x = %f, size_y = %f\n",
	     infos->global.size_x, infos->global.size_y) < 0 ||
      printf("anti-aliasing = %f, ambient_light = %f\n\n",
	     infos->global.anti_aliasing, infos->global.ambient_light) < 0)
    return (-1);
  return (0);
}

int		see_lists(t_all *all)
{
  t_object	*objects;
  t_spot	*spots;


  objects = all->objects;
  spots = all->spots;
  if (print_global(all) < 0 || printf("\nObjects:\n\n") < 0 ||
      print_object(objects) < 0 || printf("\nSpots:\n\n") < 0)
    return (-1);
  while (spots != NULL)
    {
      if (printf("Spots pos : x = %f, y = %f, z = %f\n",
		 spots->pos.x, spots->pos.y, spots->pos.z) < 0 ||
	  printf("Spots color : r = %f, g = %f, b = %f\n",
		 spots->color.r, spots->color.g, spots->color.b) < 0 ||
	  printf("Orientation = %f\nIntensity = %f\nRadius = %f\n\n",
		 spots->orientation, spots->intensity, spots->radius) < 0)
	return (-1);
      spots = spots->next;
    }
  return ((printf("\n") < 0) ? -1 : 0);
}
