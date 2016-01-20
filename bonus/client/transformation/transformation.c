/*
** transformations.c for transformations in /home/maillo_f/rendu/raytracer_tmp/transformation
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 22:31:06 2014 maillot
** Last update Sun Jun  8 11:34:53 2014 borel_d
*/

#include	"raytracer.h"
#include	"transformation.h"

void		translation(t_eye *eye, t_object *object, int i)
{
  if (i == 1)
    {
      eye->pos.x = eye->pos.x - object->pos.x;
      eye->pos.y = eye->pos.y - object->pos.y;
      eye->pos.z = eye->pos.z - object->pos.z;
    }
  else
    {
      eye->pos.x = eye->pos.x + object->pos.x;
      eye->pos.y = eye->pos.y + object->pos.y;
      eye->pos.z = eye->pos.z + object->pos.z;
    }
}

void		translation_vect(t_coord *coord, t_object *object, int i)
{
  if (i == 1)
    {
      coord->x = coord->x - object->pos.x;
      coord->y = coord->y - object->pos.y;
      coord->z = coord->z - object->pos.z;
    }
  else
    {
      coord->x = coord->x + object->pos.x;
      coord->y = coord->y + object->pos.y;
      coord->z = coord->z + object->pos.z;
    }
}
