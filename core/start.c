/*
** start.c for start in /home/borel_d/Downloads/raytracer/raytracer_tmp/core
** 
** Made by borel_d
** Login   <borel_d@epitech.net>
** 
** Started on  Sun Jun  8 17:52:03 2014 borel_d
** Last update Sun Jun  8 23:28:38 2014 maillot
*/

#include		<stdio.h>
#include		"transformation.h"
#include		"raytracer.h"
#include		"core.h"

static void		check_aa(t_all *data UNUSED)
{
  int			tab[] = {1, 2, 4, 8, 16};
  int			i;

  i = 5;
  while (--i >= 0)
    if (data->global.anti_aliasing > tab[i])
      {
	data->global.anti_aliasing = tab[i];
	return ;
      }
  data->global.anti_aliasing = 1;
}

static int		init_struct_data(t_all *data)
{
  check_aa(data);
  if ((data->win = malloc(sizeof(t_windows))) == NULL ||
      (data->img = malloc(sizeof(t_mlximg))) == NULL)
    {
      printf("Failed malloc\n");
      return (1);
    }
  return (0);
}

static int		my_call_thread(t_all *data)
{
  pthread_mutex_t	mutex;
  t_thread_data		thread[CORE];
  pthread_t		th[CORE];
  int			i;

  i = 0;
  pthread_mutex_init(&mutex, NULL);
  while (i < CORE)
    {
      thread[i].data = data;
      thread[i].mod = 1 + i;
      thread[i].mutex = &mutex;
      pthread_create(&th[i], NULL, raytracer_display, &thread[i]);
      ++i;
    }
  i = 0;
  while (i < CORE)
    pthread_join(th[i++], NULL);
  return (0);
}

int			core_start(t_all *data)
{
  if (init_struct_data(data) == 1 ||
      init_raytracer_win_img(data) == 1 ||
      my_call_thread(data) == 1)
    return (1);
  mlx_key_hook(data->win->win_ptr, &key_control, &data);
  mlx_expose_hook(data->win->win_ptr, &my_control_expose, data);
  mlx_loop(data->win->mlx_ptr);
  return (0);
}
