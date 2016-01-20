/*
** limit_init.c for limit_init in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sun Jun  8 14:43:19 2014 maillot
** Last update Sun Jun  8 18:48:20 2014 maillot
*/

#include	<float.h>
#include	"raytracer.h"
#include	"core.h"
#include	"transformation.h"

void		init_limit_rayon_x(t_object *object, double *xf, double *xb)
{
  if (object->limits_inf.x < -(object->infos / 2) || object->limits_inf.x >= 0)
    object->limits_inf.x = -(object->infos / 2);
  if (object->limits_sup.x > (object->infos / 2) || object->limits_sup.x <= 0)
    object->limits_sup.x = object->infos / 2;
  *xf = -(object->infos / 2) - (-object->limits_inf.x);
  *xb = (object->infos / 2) + (object->limits_sup.x);
}

void		init_limit_rayon_y(t_object *object, double *yl, double *yr)
{
  if (object->limits_inf.y < -(object->infos / 2) || object->limits_inf.y >= 0)
    object->limits_inf.y = -(object->infos / 2);
  if (object->limits_sup.y > (object->infos / 2) || object->limits_sup.y <= 0)
    object->limits_sup.y = object->infos / 2;
  *yl = -(object->limits_inf.y) * 2;
  *yr = object->limits_sup.y * 2;
  *yr = *yr * -1;
}

void		init_limit_rayon_z(t_object *object, double *zt, double *zb)
{
  if (object->limits_inf.z < -(object->infos / 2) || object->limits_inf.z >= 0)
    object->limits_inf.z = -(object->infos / 2);
  if (object->limits_sup.z > (object->infos / 2) || object->limits_sup.z <= 0)
    object->limits_sup.z = (object->infos / 2);
  *zt = object->limits_sup.z * 2;
  *zb = object->limits_inf.z * 2;
}

void		init_limit_inf_x(t_object *object, double *xf, double *xb)
{
  if (object->limits_inf.x > 0)
    object->limits_inf.x = 0;
  if (object->limits_sup.x < 0)
    object->limits_inf.x = 0;
  *xf = (-object->limits_inf.x);
  *xb = (object->limits_sup.x);
  if (*xb == 0)
    *xb = DBL_MAX;
  if (*xf == 0)
    *xf = -DBL_MAX;
}

void		init_limit_inf_y(t_object *object, double *yl, double *yr)
{
  if (object->limits_inf.y > 0)
    object->limits_inf.y = 0;
  if (object->limits_sup.y < 0)
    object->limits_inf.y = 0;
  *yl = -(object->limits_inf.y);
  *yr = object->limits_sup.y;
  *yr = *yr * -1;
  if (*yr == 0)
    *yr = -DBL_MAX;
  if (*yl == 0)
    *yl = DBL_MAX;
}
