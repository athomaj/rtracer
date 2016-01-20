/*
** limit_next_init.c for limit next init in /home/maillo_f/rendu/raytracer_tmp
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sun Jun  8 16:19:57 2014 maillot
** Last update Sun Jun  8 23:25:06 2014 maillot
*/

#include	<float.h>
#include	"raytracer.h"
#include	"core.h"

int		check_limit_x(t_eye *eye, t_object *object, double r1r2[2],
			      double res[2])
{
  if ((res[1] = limit_x(eye, object, r1r2)) != 0)
    {
      if (res[1] == -1)
	return (-1);
      if (res[0] > res[1])
	res[0] = res[0];
      else
	res[0] = res[1];
    }
  return (0);
}

int		check_limit_y(t_eye *eye, t_object *object, double r1r2[2],
			      double res[2])
{
  if ((res[1] = limit_y(eye, object, r1r2)) != 0)
    {
      if (res[1] == -1)
	return (-1);
      if (res[0] > res[1])
	res[0] = res[0];
      else
	res[0] = res[1];
    }
  return (0);
}

void		init_limit_inf_z(t_object *object, double *zt, double *zb)
{
  if (object->limits_inf.z > 0)
    object->limits_inf.z = 0;
  if (object->limits_sup.z < 0)
    object->limits_inf.z = 0;
  *zt = object->limits_sup.z;
  *zb = object->limits_inf.z;
  if (*zt == 0)
    *zt = DBL_MAX;
  if (*zb == 0)
    *zb = -DBL_MAX;
}
