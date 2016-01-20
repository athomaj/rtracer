/*
** init_core_functions.c for init core functions in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Mon May 26 17:13:45 2014 maillot
** Last update Sun Jun  8 22:09:23 2014 lagier_e
*/

#include	"raytracer.h"
#include	"core.h"

void		init_struct_eye(t_all *data, t_eye *eye, double x, double y)
{
  eye->pos.x = data->eye.pos.x;
  eye->pos.y = data->eye.pos.y;
  eye->pos.z = data->eye.pos.z;
  eye->rot.x = data->eye.rot.x;
  eye->rot.y = data->eye.rot.y;
  eye->rot.z = data->eye.rot.z;
  eye->vectv.x = -(data->global.size_x / (2 * tan(15)));
  eye->vectv.y = ((data->global.size_x / 2) - x);
  eye->vectv.z = ((data->global.size_y / 2) - y);
  eye->vectn.x = 0.0;
  eye->vectn.y = 0.0;
  eye->vectn.z = 0.0;
  eye->fill_light = data->global.ambient_light;
}

void		init_struct_pixel(t_pixel *pixel)
{
  pixel->typ = 0;
  pixel->k = 0.0;
  pixel->r = 0;
  pixel->g = 0;
  pixel->b = 0;
}

static int	init_raytracer_img(UNUSED t_all *data, t_windows *win,
				   t_mlximg *img)
{
  if ((img->img_ptr = mlx_new_image(win->mlx_ptr, 1000,
				    1000)) == NULL ||
      (img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp),
				     &(img->sizeline),
				     &(img->endian))) == NULL)
    {
      printf("Error during initialization of image.\n");
      return (1);
    }
  return (0);
}

static int	init_raytracer_win(UNUSED t_all *data, t_windows *win)
{
  if ((win->mlx_ptr = mlx_init()) == 0)
    {
      printf("Error during initialization of mxl_init.\n");
      return (1);
    }
  win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, WIN_NAME);
  if (win->win_ptr == NULL)
    {
      printf("Error during initialization of the window.\n");
      return (1);
    }
  return (0);
}

int		init_raytracer_win_img(t_all *data)
{
  if (init_raytracer_win(data, data->win) ||
      init_raytracer_img(data, data->win, data->img))
    return (1);
  return (0);
}
