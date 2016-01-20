/*
** core_mlx.c for core mlx in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Fri May 30 11:56:44 2014 maillot
** Last update Sun Jun  8 18:14:42 2014 borel_d
*/

#include	"raytracer.h"
#include	"core.h"

int		key_control(int key, t_all **data)
{
  if (key == ESCAPE)
    {
      mlx_destroy_window((*data)->win->mlx_ptr, (*data)->win->win_ptr);
      exit(0);
    }
  return (0);
}

int		my_control_expose(t_all *data)
{
  mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
                          data->img->img_ptr, 0, 0);
  return (0);
}

void		save_in_pixel(t_pixel *pxl, t_pixel *pxl_tmp)
{
  pxl_tmp->typ = pxl->typ;
  pxl_tmp->r = pxl->r;
  pxl_tmp->g = pxl->g;
  pxl_tmp->b = pxl->b;
  pxl_tmp->k = pxl->k;
}

void            my_pixel_put_to_img(t_all *data, t_pixel *pts, int x, int y)
{
  int		where;

  where = (y * data->img->sizeline) + (x * (data->img->bpp / 8));
  if (data->img->endian == 0)
    {
      data->img->data[where] = pts->b;
      data->img->data[where + 1] = pts->g;
      data->img->data[where + 2] = pts->r;
      return ;
    }
  data->img->data[where] = pts->r;
  data->img->data[where + 1] = pts->g;
  data->img->data[where + 2] = pts->b;
}
