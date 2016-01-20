/*
** lum.c for rtv1 in /home/archer_j/rendu/MUL_2013_rtv1
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Fri Feb 28 10:54:24 2014 archer
** Last update Sun Jun  8 23:26:28 2014 borel_d
*/

#include	<stdlib.h>
#include	<math.h>
#include	"transformation.h"
#include	"raytracer.h"
#include	"core.h"

void		rotate_vect(t_coord *n, t_object *object, int sens)
{
  rotate_z(&n->x, &n->y, &n->z, object->rot.z * sens);
  rotate_y(&n->x, &n->y, &n->z, object->rot.y * sens);
  rotate_x(&n->x, &n->y, &n->z, object->rot.x * sens);
}

double		calc_cos(t_coord *spot, t_coord *pt_inter,
			 t_coord *vect_n, double vnnorm)
{
  t_coord	vect_l;
  double	scal;
  double	cos;

  vect_l.x = spot->x - pt_inter->x;
  vect_l.y = spot->y - pt_inter->y;
  vect_l.z = spot->z - pt_inter->z;
  scal = vnnorm *
    sqrt(pow(vect_l.x, 2) + pow(vect_l.y, 2) + pow(vect_l.z, 2));
  cos = (vect_n->x * vect_l.x + vect_n->y * vect_l.y +
	 vect_n->z * vect_l.z) / scal;
  return ((cos < 0) ? 0 : cos);
}

void		calc_vector_n(t_object *obj, t_coord *inter, t_coord *vect_n)
{
  t_coord	n[4];

  if (obj->type != PLAN)
    rotate_vect(inter, obj, -1);
  n[SPHERE].x = inter->x;
  n[SPHERE].y = inter->y;
  n[SPHERE].z = inter->z;
  n[PLAN].x = 0;
  n[PLAN].y = 0;
  n[PLAN].z = 100;
  n[CYLINDRE].x = inter->x;
  n[CYLINDRE].y = inter->y;
  n[CYLINDRE].z = 0;
  n[CONE].x = inter->x;
  n[CONE].y = inter->y;
  n[CONE].z = pow(tan(obj->infos), 2) * inter->z;
  n[obj->type].x = n[obj->type].x - obj->pos.x;
  n[obj->type].y = n[obj->type].y - obj->pos.y;
  n[obj->type].z = n[obj->type].z - obj->pos.z;
  if (obj->type != PLAN)
    {
      rotate_vect(&n[obj->type], obj, 1);
      rotate_vect(inter, obj, 1);
    }
  *vect_n = n[obj->type];
}

int		calc_obj(t_object *objects, t_object *object, t_eye *eye_tmp)
{
  t_pixel	pixel_tmp;
  int		i;

  i = 0;
  while (objects != NULL)
    {
      calculates_shape(&pixel_tmp, eye_tmp, objects);
      if (pixel_tmp.k > 0 && pixel_tmp.k < 1 && object != objects)
	++i;
      objects = objects->next;
    }
  return (i);
}
