/*
** init_intersection.c for init intersection in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 22:12:10 2014 maillot
** Last update Sun Jun  8 18:22:03 2014 borel_d
*/

#include	"raytracer.h"
#include	"core.h"
#include	"transformation.h"

static void	save_in_pxl_tmp(t_pixel *pxl_tmp, t_object *object)
{
  pxl_tmp->typ = object->type;
  pxl_tmp->r = object->color.r;
  pxl_tmp->g = object->color.g;
  pxl_tmp->b = object->color.b;
}

static void	init_tab_int_ptr(int tab_int[4],
				 double (*fptr[5])(t_eye *, t_object *))
{
  tab_int[0] = PLAN;
  tab_int[1] = CONE;
  tab_int[2] = SPHERE;
  tab_int[3] = CYLINDRE;
  fptr[0] = &inter_plan;
  fptr[1] = &inter_cone;
  fptr[2] = &inter_sphere;
  fptr[3] = &inter_cylinder;
}

void		calculates_shape(t_pixel *pxl_tmp, t_eye *eye,
				 t_object *read_object)
{
  double	(*fptr[5])(t_eye *, t_object *);
  int		tab_int[4];
  int		i;

  init_tab_int_ptr(tab_int, fptr);
  translation(eye, read_object, 1);
  rotate_pos_vec(eye, read_object, -1);
  i = -1;
  while (++i < 4 && read_object->type != tab_int[i]);
  if (i < 4 && read_object->type == tab_int[i])
    pxl_tmp->k = fptr[i](eye, read_object);
  else if (i == 4)
    pxl_tmp->k = -1.0;
  rotate_pos_vec(eye, read_object, 1);
  translation(eye, read_object, 0);
  save_in_pxl_tmp(pxl_tmp, read_object);
}
