/*
** main.c for server in /home/lagier_e/rendu/test/network_test
**
** Made by lagier_e
** Login   <lagier_e@epitech.net>
**
** Started on  Thu May 29 16:52:42 2014 lagier_e
** Last update Sun Jun  8 23:27:13 2014 lagier_e
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<netinet/in.h>
#include	<pthread.h>
#include	<mlx.h>
#include	<errno.h>
#include	"server.h"

int			my_mlx_loop(t_serv *serv)
{
  mlx_key_hook(serv->win.win, &manage_key, NULL);
  mlx_expose_hook(serv->win.win, &manage_expose, serv);
  mlx_loop(serv->win.ptr);
  return (0);
}

int			main(int argc, char **argv)
{
  t_servd		servd[MCO];
  t_serv		serv;
  pthread_t		thread[MCO];
  int			i;

  i = 0;
  if (argc != 2)
    return (my_error("Usage: ./server port\n", 0, 10));
  if (ini_server(argv[1], &serv) == -1)
    return (-1);
  if (ini_win(&serv) == -1)
    return (-1);
  main_loop(servd, thread, &serv);
  while (i < MCO)
    {
      pthread_join(thread[i], NULL);
      i = i + 1;
    }
  my_mlx_loop(&serv);
  pthread_mutex_lock(&serv.mutex);
  mlx_put_image_to_window(serv.win.ptr, serv.win.win, serv.win.img, 0, 0);
  pthread_mutex_unlock(&serv.mutex);
  close(serv.sockfd);
  return (0);
}
