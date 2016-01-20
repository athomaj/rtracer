/*
** limit.c for limit in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Thu Jun  5 17:34:01 2014 maillot
** Last update Sun Jun  8 17:07:55 2014 maillot
*/

#include	<float.h>
#include	"raytracer.h"
#include	"core.h"
#include	"transformation.h"

double		limit_x(t_eye *eye, t_object *object, double r1r2[2])
{
  double	rx;
  double	xf;
  double	xb;

  if (object->type == CYLINDRE || object->type == SPHERE)
    init_limit_rayon_x(object, &xf, &xb);
  else
    init_limit_inf_x(object, &xf, &xb);
  rx = eye->vectv.x * r1r2[0] + eye->pos.x;
  if (rx < (xf))
    {
      rx = eye->vectv.x * r1r2[1] + eye->pos.x;
      if (rx > (xb))
	return (-1);
      return (r1r2[0]);
    }
  if (rx < (xb))
    {
      rx = eye->vectv.x * r1r2[1] + eye->pos.x;
      if (rx > (xb))
	return (r1r2[1]);
      return (r1r2[0]);
    }
  return (r1r2[0]);
}

double		limit_y(t_eye *eye, t_object *object, double r1r2[2])
{
  double	ry;
  double	yl;
  double	yr;

  if (object->type == CYLINDRE || object->type == SPHERE)
    init_limit_rayon_y(object, &yl, &yr);
  else
    init_limit_inf_y(object, &yl, &yr);
  ry = eye->vectv.y * r1r2[0] + eye->pos.y;
  if (ry > (yl))
    {
      ry = eye->vectv.y * r1r2[1] + eye->pos.y;
      if (ry > (yl))
	return (-1);
      return (r1r2[1]);
    }
  else if (ry < (yr))
    {
      ry = eye->vectv.y * r1r2[1] + eye->pos.y;
      if (ry < (yr))
	return (-1);
      return (r1r2[1]);
    }
  return (r1r2[0]);
}

double		limit_z(t_eye *eye, t_object *object, double r1r2[2])
{
  double	rz;
  double	zt;
  double	zb;

  if (object->type == CYLINDRE || object->type == CONE)
    init_limit_inf_z(object, &zt, &zb);
  else
    init_limit_rayon_z(object, &zt, &zb);
  rz = eye->vectv.z * r1r2[0] + eye->pos.z;
  if (rz > (zt))
    {
      rz = eye->vectv.z * r1r2[1] + eye->pos.z;
      if (rz > (zt))
	return (-1);
      return (r1r2[1]);
    }
  else if (rz < (zb))
    {
      rz = eye->vectv.z * r1r2[1] + eye->pos.z;
      if (rz < (zb))
	return (-1);
      return (r1r2[1]);
    }
  return (r1r2[0]);
}

double		init_limit(t_eye *eye, t_object *object, double abcrd[5])
{
  double	r1r2[2];
  double	res[2];

  if (abcrd[4] < 0.0)
    return (-1);
  if (abcrd[4] == 0.0)
    return (-(abcrd[1]) / (2 * abcrd[0]));
  if (abcrd[4] >= 0.0)
    {
      r1r2[0] = (-abcrd[1] - sqrtf(abcrd[4])) / (2 * abcrd[0]);
      r1r2[1] = (-abcrd[1] + sqrtf(abcrd[4])) / (2 * abcrd[0]);
      if (r1r2[0] < 0.0 || (r1r2[1] > 0.0 && r1r2[1] < r1r2[0]))
	r1r2[0] = r1r2[1];
      res[0] = limit_z(eye, object, r1r2);
      if (res[0] != -1)
	if (check_limit_x(eye, object, r1r2, res) == -1 ||
	    check_limit_y(eye, object, r1r2, res) == -1)
	  return (-1);
      return (res[0]);
    }
  return (res[0]);
}
