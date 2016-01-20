/*
** check_function.c for check_function.c in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 23:08:54 2014 maillot
** Last update Sun Jun  8 17:28:21 2014 borel_d
*/

#include	"raytracer.h"
#include	"core.h"

void		check_k(t_pixel *pxl_tmp, UNUSED t_all *all,
			UNUSED t_object *object, UNUSED t_eye *eye)
{
  if (pxl_tmp->k == -1.0)
    {
      pxl_tmp->r = 0.0;
      pxl_tmp->g = 0.0;
      pxl_tmp->b = 0.0;
    }
  else if (pxl_tmp->k > 0)
    init_lum_shadow(all, object, pxl_tmp, eye);
}

int		check_diff_between_tmp_and_buff(t_pixel *pxl_tmp,
						t_pixel *pxl_buffer)
{
  if ((pxl_tmp && pxl_buffer->act == 1 && pxl_tmp->k >= 0.0 &&
       pxl_buffer->k <= pxl_tmp->k && pxl_buffer->k >= 0.0) ||
      (pxl_tmp && pxl_buffer->act == 1 && pxl_tmp->k < 0.0 &&
       pxl_buffer->k >= 0.0))
    return (0);
  pxl_buffer->k = pxl_tmp->k;
  pxl_buffer->typ = pxl_tmp->typ;
  pxl_buffer->r = pxl_tmp->r;
  pxl_buffer->g = pxl_tmp->g;
  pxl_buffer->b = pxl_tmp->b;
  return (0);
}
