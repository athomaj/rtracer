/*
** reflection.c for reflection in /home/borel_d/Desktop/raytracer_tmp/shadowlight
** 
** Made by borel_d
** Login   <borel_d@epitech.net>
** 
** Started on  Fri Jun  6 17:30:37 2014 borel_d
** Last update Sun Jun  8 23:30:52 2014 borel_d
*/

#include	"core.h"
#include	"raytracer.h"

static int	is_closer(t_pixel *pxl_tmp, t_eye *eye_tmp,
			  t_object *obj_tmp, double *k)
{
  calculates_shape(pxl_tmp, eye_tmp, obj_tmp);
  if (pxl_tmp->k > 0 && pxl_tmp->k < *k)
    {
      *k = pxl_tmp->k;
      return (1);
    }
  return (0);
}

static void	new_colors(t_object **obj, t_object *new_obj,
			   t_pixel *pixel, t_pixel *new_pxl)
{
  *obj = new_obj;
  new_pxl->r = pixel->r;
  new_pxl->g = pixel->g;
  new_pxl->b = pixel->b;
}

void		init_reflection(t_eye *eye, t_eye *old_eye,
				t_coord *v_nrm, t_coord *pt_inter)
{
  t_coord	*v_ray;
  double	scalaire;

  v_ray = &old_eye->vectv;
  scalaire = v_nrm->x * v_ray->x + v_nrm->y * v_ray->y + 
    v_nrm->z * v_ray->z;
  eye->pos = *pt_inter;
  eye->rot.x = 0.0;
  eye->rot.y = 0.0;
  eye->rot.z = 0.0;
  eye->vectv.x = v_ray->x - (2 * v_nrm->x * scalaire);
  eye->vectv.y = v_ray->y - (2 * v_nrm->y * scalaire);
  eye->vectv.z = v_ray->z - (2 * v_nrm->z * scalaire);
  eye->vectn.x = 0.0;
  eye->vectn.y = 0.0;
  eye->vectn.z = 0.0;
}

static void	set_final_colors(t_pixel *pixel, t_pixel *final_pxl,
				 float *reflx)
{
  pixel->r = final_pxl->r * *reflx + pixel->r * (1 - *reflx);
  pixel->g = final_pxl->g * *reflx + pixel->g * (1 - *reflx);
  pixel->b = final_pxl->b * *reflx + pixel->b * (1 - *reflx);
}

void		reflection(t_all *all, t_object *object,
			   t_pixel *pixel, t_eye *eye_tmp)
{
  t_object	*obj_tmp;
  t_object	*target;
  t_pixel	pxl_tmp;
  t_pixel	final_pxl;
  double	k;
  float		reflx;

  obj_tmp = all->objects;
  reflx = (float) object->reflexion / 100;
  init_struct_pixel(&pxl_tmp);
  k = 9999.0;
  target = NULL;
  while (obj_tmp != NULL)
    {
      if (obj_tmp != object &&
	  is_closer(&pxl_tmp, eye_tmp, obj_tmp, &k) == 1)
	new_colors(&target, obj_tmp, &pxl_tmp, &final_pxl);
      obj_tmp = obj_tmp->next;
    }
  if (target == NULL)
    return ;
  init_lum_shadow(all, target, &final_pxl, eye_tmp);
  set_final_colors(pixel, &final_pxl, &reflx);
}
