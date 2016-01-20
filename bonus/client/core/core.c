/*
** core.c for core in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Mon May 26 16:50:03 2014 maillot
** Last update Sun Jun  8 18:06:52 2014 borel_d
*/

#include	"transformation.h"
#include	"raytracer.h"
#include	"core.h"

static int	calc_intersection(t_all *data, t_eye *eye,
				  t_pixel *pxl_buffer, t_object *read_object)
{
  t_pixel	pxl_tmp;

  data->travels = 0;
  calculates_shape(&pxl_tmp, eye, read_object);
  check_k(&pxl_tmp, data, read_object, eye);
  check_diff_between_tmp_and_buff(&pxl_tmp, pxl_buffer);
  pxl_buffer->act = 1;
  return (0);
}

static int	init_and_calc_inter_point(t_all *data, t_pixel *pxl_buffer,
					  double x, double y)
{
  t_object	*read_objects;
  t_eye		eye;

  pxl_buffer->act = 0;
  init_struct_eye(data, &eye, x, y);
  rotate_eye(&eye);
  read_objects = data->objects;
  while (read_objects != NULL)
    {
      if (calc_intersection(data, &eye, pxl_buffer, read_objects) == 1)
	return (1);
      read_objects = read_objects->next;
    }
  return (0);
}

static void	anti_aliasing(t_pixel *pxl, double anti_aliasing)
{
  anti_aliasing *= anti_aliasing;
  pxl->r /= anti_aliasing;
  pxl->g /= anti_aliasing;
  pxl->b /= anti_aliasing;
}

int		calc_precision_intersection(t_all *data, t_pixel *pxl,
					    int x, int y)
{
  t_pixel	pxl_buffer;
  double	x_bis;
  double	y_bis;

  x_bis = (double)x;
  init_struct_pixel(pxl);
  while (x_bis < (double)(x + 1))
    {
      y_bis = (double)y;
      while (y_bis < (double)(y + 1))
	{
	  init_struct_pixel(&pxl_buffer);
	  if (init_and_calc_inter_point(data, &pxl_buffer, x_bis, y_bis) == 1)
	    return (1);
	  pxl->r += pxl_buffer.r;
	  pxl->g += pxl_buffer.g;
	  pxl->b += pxl_buffer.b;
	  y_bis += 1.0 / data->global.anti_aliasing;
	}
      x_bis += 1.0 / data->global.anti_aliasing;
    }
  anti_aliasing(pxl, data->global.anti_aliasing);
  pxl->k = pxl_buffer.k;
  return (0);
}
