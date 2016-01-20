/*
** thread_core.c for rt in /home/lagier_e/rendu/raytracer_tmp/core
** 
** Made by lagier_e
** Login   <lagier_e@epitech.net>
** 
** Started on  Mon Jun  2 16:54:35 2014 lagier_e
** Last update Sun Jun  8 17:48:04 2014 borel_d
*/

#include	"raytracer.h"
#include	"core.h"
#include	"transformation.h"

static void	init_basics(t_thread_data **thread, void *param,
			    t_all **data, int *y)
{
  *thread = param;
  *data = (*thread)->data;
  *y = (*thread)->mod;
  (*data)->img->data = mlx_get_data_addr((*data)->img->img_ptr,
					 &((*data)->img->bpp),
					 &((*data)->img->sizeline),
					 &((*data)->img->endian));
}

void		*raytracer_display(void *param)
{
  int		x;
  int		y;
  t_pixel	pxl;
  t_all		*data;
  t_thread_data	*thread;

  init_basics(&thread, param, &data, &y);
  while (y < data->global.size_y)
    {
      x = -1;
      while (++x < data->global.size_x &&
	     calc_precision_intersection(data, &pxl, x, y) != 1)
        if (pxl.k >= 0 && pthread_mutex_lock(thread->mutex) >= 0)
	  {
	    my_pixel_put_to_img(data, &pxl, x, y);
	    pthread_mutex_unlock(thread->mutex);
	  }
      pthread_mutex_lock(thread->mutex);
      mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			      data->img->img_ptr, 0, 0);
      pthread_mutex_unlock(thread->mutex);
      y = y + CORE;
    }
  return (NULL);
}
