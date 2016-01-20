/*
** libx_func.c for server in /home/lagier_e/rendu/test_rt/MUL_2013_rtv1/network/server_src
** 
** Made by lagier_e
** Login   <lagier_e@epitech.net>
** 
** Started on  Sun Jun  8 14:58:19 2014 lagier_e
** Last update Sun Jun  8 23:24:30 2014 lagier_e
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<pthread.h>
#include	<mlx.h>
#include	"server.h"

void		my_pixel(char *img, int x, int y, int c)
{
  int		pos;
  char		*color;

  color = (char *)&c;
  if (x < 0 || y < 0 || x > 1920 || y > 1080)
    return;
  pos = (y * 1920) * 4;
  pos = pos + (x * 4);
  img[pos] = color[0];
  img[pos + 1] = color[1];
  img[pos + 2] = color[2];
}

int		manage_key(int keycode, __attribute__((unused))void *param)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

int			ini_win(t_serv *serv)
{
  if ((serv->win.ptr = mlx_init()) == NULL)
    return (-1);
  if ((serv->win.win = mlx_new_window(serv->win.ptr,
				      serv->xwin, serv->ywin,
				      "server")) == NULL)
    return (-1);
  if ((serv->win.img = mlx_new_image(serv->win.ptr,
				     serv->xwin, serv->ywin)) == NULL)
    return (-1);
  if ((serv->win.data = mlx_get_data_addr(serv->win.img,
					  &serv->win.bpp, &serv->win.size,
				     &serv->win.endian)) == NULL)
    return (-1);
  mlx_key_hook(serv->win.win, &manage_key, NULL);
  mlx_expose_hook(serv->win.win, &manage_expose, serv);
  ini_background(serv->win.data, 0x0000FF, serv);
  pthread_mutex_lock(&serv->mutex);
  mlx_put_image_to_window(serv->win.ptr, serv->win.win,
			  serv->win.img, 0, 0);
  pthread_mutex_unlock(&serv->mutex);
  return (0);
}
