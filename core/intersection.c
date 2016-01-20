/*
** intersection.c for intersection in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 22:51:50 2014 maillot
** Last update Sun Jun  8 21:14:01 2014 maillot
*/

#include	"raytracer.h"
#include	"core.h"

double		inter_plan(t_eye *eye, t_object __attribute__((unused)) *object)
{
  double	k;

  if (eye->vectv.z == 0.0000)
    k = -1.0;
  else
    k = -(eye->pos.z / eye->vectv.z);
  return (k);
}

double		inter_sphere(t_eye *eye, t_object *object)
{
  double	abcrd[5];

  abcrd[3] = object->infos;
  abcrd[0] = pow(eye->vectv.x, 2.00) + pow(eye->vectv.y, 2.00) +
    pow(eye->vectv.z, 2.00);
  abcrd[1] = (2.0 * eye->vectv.x * eye->pos.x) +
    (2.0 * eye->vectv.y * eye->pos.y) +
    (2.0 * eye->vectv.z * eye->pos.z);
  abcrd[2] = pow(eye->pos.x, 2.00) + pow(eye->pos.y, 2.00) +
    pow(eye->pos.z, 2.00) - pow((abcrd[3]), 2.00);
  abcrd[4] = ((abcrd[1]) * (abcrd[1])) - (4 * (abcrd[0]) * (abcrd[2]));
  return (init_limit(eye, object, abcrd));
}

double		inter_cylinder(t_eye *eye, t_object *object)
{
  double	abcrd[5];

  abcrd[3] = object->infos;
  abcrd[0] = pow(eye->vectv.x, 2) + pow(eye->vectv.y, 2);
  abcrd[1] = ((2 * eye->vectv.x * eye->pos.x) +
	      (2 * eye->vectv.y * eye->pos.y));
  abcrd[2] = pow(eye->pos.x, 2) + pow(eye->pos.y, 2) - pow((abcrd[3]), 2);
  abcrd[4] = ((abcrd[1]) * (abcrd[1])) - (4 * (abcrd[0]) * (abcrd[2]));
  return (init_limit(eye, object, abcrd));
}

double		inter_cone(t_eye *eye, t_object *object)
{
  double	abcrd[5];

  abcrd[3] = object->infos * M_PI / 180;
  abcrd[0] = pow(eye->vectv.x, 2) + pow(eye->vectv.y, 2) -
    (pow(eye->vectv.z, 2) * (pow(tan((abcrd[3])), 2)));
  abcrd[1] = (2 * eye->vectv.x * eye->pos.x) +
    (2 * eye->vectv.y * eye->pos.y) -
    ((2 * eye->vectv.z * eye->pos.z) * (pow(tan((abcrd[3])), 2)));
  abcrd[2] = (pow(eye->pos.x, 2) + pow(eye->pos.y, 2) -
	      (pow(eye->pos.z, 2) * pow(tan((abcrd[3])), 2)));
  abcrd[4] = ((abcrd[1]) * (abcrd[1])) - (4 * (abcrd[0]) * (abcrd[2]));
  return (init_limit(eye, object, abcrd));
}
