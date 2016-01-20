/*
** ray_travel.c for ray_travel in /home/borel_d/Downloads/raytracer/raytracer_tmp/shadowlight
** 
** Made by borel_d
** Login   <borel_d@epitech.net>
** 
** Started on  Sat Jun  7 23:56:16 2014 borel_d
** Last update Sun Jun  8 23:29:49 2014 borel_d
*/

#include	<math.h>
#include	"core.h"
#include	"raytracer.h"
#include	"transformation.h"

static void	new_eye_posi(t_eye *eye_tmp, t_spot *tmp_spot,
			     t_coord *pt_inter)
{
  eye_tmp->vectv.x = tmp_spot->pos.x - pt_inter->x;
  eye_tmp->vectv.y = tmp_spot->pos.y - pt_inter->y;
  eye_tmp->vectv.z = tmp_spot->pos.z - pt_inter->z;
}

static void	init_struct(t_eye *eye, t_eye *eye_tmp,
			    t_coord *pt_inter, t_pixel *pixel)
{
  pt_inter->x = eye->pos.x + (eye->vectv.x * pixel->k);
  pt_inter->y = eye->pos.y + (eye->vectv.y * pixel->k);
  pt_inter->z = eye->pos.z + (eye->vectv.z * pixel->k);
  eye_tmp->pos.x = pt_inter->x;
  eye_tmp->pos.y = pt_inter->y;
  eye_tmp->pos.z = pt_inter->z;
  eye_tmp->rot.x = eye->rot.x;
  eye_tmp->rot.y = eye->rot.y;
  eye_tmp->rot.z = eye->rot.z;
  eye_tmp->fill_light = eye->fill_light;
}

static void	set_shadows(t_pixel *pixel, double *shadow)
{
  if ((*shadow = 1 - *shadow) < 0)
    *shadow = 0;
  pixel->r = WIN(pixel->r * *shadow, 0, 255);
  pixel->g = WIN(pixel->g * *shadow, 0, 255);
  pixel->b = WIN(pixel->b * *shadow, 0, 255);
}

void		init_lum_shadow(t_all *infos, t_object *object,
				t_pixel *pixel, t_eye *eye)
{
  t_spot	*tmp_spot;
  t_coord	pt_inter;
  t_coord	v_norm;
  t_eye		eye_tmp;
  double	shadow;

  init_struct(eye, &eye_tmp, &pt_inter, pixel);
  lum_shadow(infos, &pt_inter, object, pixel);
  tmp_spot = infos->spots;
  shadow = 0;
  while (tmp_spot != NULL)
    {
      new_eye_posi(&eye_tmp, tmp_spot, &pt_inter);
      if (calc_obj(infos->objects, object, &eye_tmp) > 0)
        shadow += ((double) WIN(tmp_spot->intensity, 0, 100)) / SHADOW_FACTOR;
      tmp_spot = tmp_spot->next;
    }
  set_shadows(pixel, &shadow);
  if (object->reflexion > 0 && ++infos->travels < TRAVEL_LIMIT)
    {
      calc_vector_n(object, &pt_inter, &v_norm);
      init_reflection(&eye_tmp, eye, &v_norm, &pt_inter);
      reflection(infos, object, pixel, &eye_tmp);
    }
}
