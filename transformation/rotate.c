/*
** rotate.c for rotate in /home/maillo_f/rendu/raytracer_tmp/transformation
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 21:25:07 2014 maillot
** Last update Sun Jun  8 16:22:20 2014 borel_d
*/

#include	"raytracer.h"
#include	"core.h"
#include	"transformation.h"

void		rotate_x(double *x, double *y, double *z, double a)
{
  double	xtmp;
  double	ytmp;
  double	ztmp;

  if (a != 0)
    {
      a = (a * 3.14159264) / 180;
      xtmp = ((*x) * 1.0) + ((*y) * 0.0) + ((*z) * 0.0);
      ytmp = ((*x) * 0.0) + ((*y) * cosf(a)) + ((*z) * -sinf(a));
      ztmp = ((*x) * 0.0) + ((*y) * sinf(a)) + ((*z) * cosf(a));
      *x = xtmp;
      *y = ytmp;
      *z = ztmp;
    }
}

void		rotate_y(double *x, double *y, double *z, double a)
{
  double	xtmp;
  double	ytmp;
  double	ztmp;

  if (a != 0.0)
    {
      a = (a * 3.14159264) / 180;
      xtmp = ((*x) * cosf(a)) + ((*y) * 0.0) + ((*z) * sinf(a));
      ytmp = ((*x) * 0.0) + ((*y) * 1.0) + ((*z) * 0.0);
      ztmp = ((*x) * -sinf(a)) + ((*y) * 0.0) + ((*z) * cosf(a));
      *x = xtmp;
      *y = ytmp;
      *z = ztmp;
    }
}

void		rotate_z(double *x, double *y, double *z, double a)
{
  double	xtmp;
  double	ytmp;
  double	ztmp;

  if (a != 0.0)
    {
      a = (a * 3.14159264) / 180;
      xtmp = ((*x) * cosf(a)) + ((*y) * -sinf(a)) + ((*z) * 0.0);
      ytmp = ((*x) * sinf(a)) + ((*y) * cosf(a)) + ((*z) * 0.0);
      ztmp = ((*x) * 0.0) + ((*y) * 0.0) + ((*z) * 1.0);
      *x = xtmp;
      *y = ytmp;
      *z = ztmp;
    }
}

void		rotate_pos_vec(t_eye *eye, t_object *object, int sens)
{
  if (object->type != SPHERE)
    {
      rotate_z(&eye->pos.x, &eye->pos.y, &eye->pos.z, object->rot.z * sens);
      rotate_y(&eye->pos.x, &eye->pos.y, &eye->pos.z, object->rot.y * sens);
      rotate_x(&eye->pos.x, &eye->pos.y, &eye->pos.z, object->rot.x * sens);
      rotate_z(&eye->vectv.x, &eye->vectv.y,
	       &eye->vectv.z, object->rot.z * sens);
      rotate_y(&eye->vectv.x, &eye->vectv.y,
	       &eye->vectv.z, object->rot.y * sens);
      rotate_x(&eye->vectv.x, &eye->vectv.y,
	       &eye->vectv.z, object->rot.x * sens);
    }
}
