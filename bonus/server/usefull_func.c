/*
** usefull_func.c for server in /home/lagier_e/rendu/test_rt/MUL_2013_rtv1/network/server_src
** 
** Made by lagier_e
** Login   <lagier_e@epitech.net>
** 
** Started on  Sun Jun  8 14:55:27 2014 lagier_e
** Last update Sun Jun  8 16:19:12 2014 lagier_e
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/stat.h>
#include	<netinet/in.h>
#include	<pthread.h>
#include	<mlx.h>
#include	"server.h"

int		my_error(char *msg, int ex, int ret)
{
  if (ret == 10)
    {
      fprintf(stderr, msg);
      return (0);
    }
  perror(msg);
  if (ex == 1)
    exit(1);
  return (ret);
}

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int			my_nb(char *buffer, int *i)
{
  int			j;
  char			nb[4096];

  j = 0;
  while (buffer[j] && buffer[j] != '*')
    {
      nb[j] = buffer[j];
      j = j + 1;
      *i = *i + 1;
    }
  *i = *i + 1;
  nb[j] = 0;
  if (buffer[j] != '*')
    return (0);
  return (atoi(nb));
}

int			manage_expose(void *param)
{
  t_serv		*serv;

  serv = param;
  pthread_mutex_lock(&serv->mutex);
  mlx_put_image_to_window(serv->win.ptr, serv->win.win, serv->win.img, 0, 0);
  pthread_mutex_unlock(&serv->mutex);
  return (1);
}

void		ini_background(char *data, int color, t_serv *serv)
{
  int		pos;
  char		*c;

  c = (char *)&color;
  pos = 0;
  while (pos < (serv->xwin * serv->ywin * 4))
    {
      data[pos] = c[0];
      data[pos + 1] = c[1];
      data[pos + 2] = c[2];
      pos = pos + 4;
    }
}
