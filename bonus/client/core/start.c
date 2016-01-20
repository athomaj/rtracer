/*
** start.c for start in /home/borel_d/Downloads/raytracer/raytracer_tmp/core
** 
** Made by borel_d
** Login   <borel_d@epitech.net>
** 
** Started on  Sun Jun  8 17:52:03 2014 borel_d
** Last update Sun Jun  8 22:10:44 2014 lagier_e
*/

#include		<string.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		"transformation.h"
#include		"raytracer.h"
#include		"core.h"

static int		init_struct_data(t_all *data)
{
  if ((data->win = malloc(sizeof(t_windows))) == NULL ||
      (data->img = malloc(sizeof(t_mlximg))) == NULL)
    {
      printf("Failed malloc\n");
      return (1);
    }
  return (0);
}

int			send_end(t_all *data)
{
  char			buffer[4006];
  int			i;

  i = 0;
  memset(buffer, 0, 4006);
  sprintf(buffer, "END");
  if (send(data->sockfd, buffer, 4005, 0) <= 0 ||
      recv(data->sockfd, buffer, 4005, MSG_WAITALL) <= 0)
    exit(0);
  data->ymin = my_nb(buffer + i + 1, &i);
  data->ymax = my_nb(buffer + i + 1, &i);
  my_call_thread(data);
  return (0);
}

int			my_call_thread(t_all *data)
{
  pthread_mutex_t	mutex;
  t_thread_data		thread[CORE];
  pthread_t		th[CORE];
  int			i;

  i = -1;
  pthread_mutex_init(&mutex, NULL);
  while (++i < CORE)
    {
      thread[i].data = data;
      thread[i].tymin = i + data->ymin;
      thread[i].tymax = data->ymax;
      thread[i].mutex = &mutex;
      pthread_create(&th[i], NULL, raytracer_display, &thread[i]);
    }
  i = 0;
  while (i < CORE)
    pthread_join(th[i++], NULL);
  send_end(data);
  return (0);
}

int			core_start(t_all *data)
{
  if (ini_connection(data->ip, atoi(data->port), data) == -1 ||
      init_struct_data(data) == 1 ||
      init_raytracer_win_img(data) == 1 ||
      my_call_thread(data) == 1)
    return (1);
  mlx_key_hook(data->win->win_ptr, &key_control, &data);
  mlx_expose_hook(data->win->win_ptr, &my_control_expose, data);
  mlx_loop(data->win->mlx_ptr);
  return (0);
}
