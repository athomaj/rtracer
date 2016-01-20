/*
** thread_core.c for rt in /home/lagier_e/rendu/raytracer_tmp/core
** 
** Made by lagier_e
** Login   <lagier_e@epitech.net>
** 
** Started on  Mon Jun  2 16:54:35 2014 lagier_e
** Last update Sun Jun  8 22:51:02 2014 lagier_e
*/

#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<errno.h>
#include	"raytracer.h"
#include	"core.h"
#include	"transformation.h"

static void	init_basics(t_thread_data **thread, void *param,
			    t_all **data, int *y)
{
  *thread = param;
  *data = (*thread)->data;
  *y = (*thread)->tymin;
  (*data)->img->data = mlx_get_data_addr((*data)->img->img_ptr,
					 &((*data)->img->bpp),
					 &((*data)->img->sizeline),
					 &((*data)->img->endian));
}

int		send_line(t_all *data, int y)
{
  int		i;
  int		j;
  char		buffer[4006];
  int		max;

  j = 0;
  memset(buffer, 0, 4006);
  i = (y * 1000) * 4;
  sprintf(buffer, "%d*", y);
  j = strlen(buffer);
  max = i + (1000 * 4);
  while (i <= max)
    buffer[j++] = data->img->data[i++];
  if (send(data->sockfd, buffer, 4005, 0) <= 0)
    exit(0);
  return (0);
}

void		*raytracer_display(void *param)
{
  int		x;
  int		y;
  t_pixel	pxl;
  t_all		*data;
  t_thread_data	*thread;

  init_basics(&thread, param, &data, &y);
  while (y < thread->tymax)
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
      send_line(data, y);
      y = y + CORE;
    }
  return (NULL);
}
