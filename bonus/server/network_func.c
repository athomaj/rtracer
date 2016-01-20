/*
** network_func.c for server in /home/lagier_e/rendu/test_rt/MUL_2013_rtv1/network/server_src
** 
** Made by lagier_e
** Login   <lagier_e@epitech.net>
** 
** Started on  Sun Jun  8 15:32:23 2014 lagier_e
** Last update Sun Jun  8 23:25:33 2014 lagier_e
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
#include	"server.h"

void			*new_listener(void *param)
{
  int			newsockfd;
  char			buffer[4096];
  int			m;
  t_serv		*serv;
  t_servd		*servd;

  servd = param;
  serv = servd->serv;
  newsockfd = servd->newsockfd;
  memset(buffer, 0, 4096);
  sprintf(buffer, "*%d*%d", servd->y, servd->ym);
  if ((m = send(newsockfd, buffer, 4005, 0)) <= 0)
    my_error("ERROR on send", 1, 0);
  show_img(newsockfd, serv, servd->ym, servd);
  return (NULL);
}

int			get_img(char *data, int sock, t_serv *serv)
{
  int			i;
  int			j;
  int			y;
  char			buffer[4006];
  int			n;

  i = 0;
  j = 0;
  memset(buffer, 0, 4006);
  if ((n = recv(sock, buffer, 4005, MSG_WAITALL)) <= 0)
    return (-1);
  if (strncmp(buffer, "END", 3) == 0)
    return (-2);
  y = my_nb(buffer, &j);
  if (y == 0)
    return (1);
  i = (y * serv->xwin) * 4;
  while (j < n)
    data[i++] = buffer[j++];
  pthread_mutex_lock(&serv->mutex);
  mlx_put_image_to_window(serv->win.ptr, serv->win.win, serv->win.img, 0, 0);
  pthread_mutex_unlock(&serv->mutex);
  return (0);
}

int			show_img(int sock, t_serv *serv, int ym,
				 t_servd *servd)
{
  int			i;
  int			ret;

  i = 0;
  ret = 0;
  while (i <= ym)
    {
      if ((ret = get_img(serv->win.data, sock, serv)) == 0)
	i = i + 1;
      if (ret == -2)
	i = ym + 1;
      pthread_mutex_lock(&serv->mutex);
      mlx_put_image_to_window(serv->win.ptr, serv->win.win,
			      serv->win.img, 0, 0);
      pthread_mutex_unlock(&serv->mutex);
    }
  pthread_mutex_lock(&serv->mutex);
  servd->y = (50 * serv->j);
  servd->ym = 51 + (50 * serv->j);
  if (servd->ym > 1001)
    my_mlx_loop(serv);
  serv->j = serv->j + 1;
  pthread_mutex_unlock(&serv->mutex);
  new_listener(servd);
  return (0);
}

int			ini_server(char *port, t_serv *serv)
{
  int			portno;
  pthread_mutex_t	mutex;

  pthread_mutex_init(&mutex, NULL);
  serv->j = 0;
  serv->mutex = mutex;
  serv->xwin = 1000;
  serv->ywin = 1000;
  if ((serv->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    my_error("ERROR opening socket", 1, 0);
  memset((char *) &serv->serv_addr, 0, sizeof(serv->serv_addr));
  portno = atoi(port);
  serv->serv_addr.sin_family = AF_INET;
  serv->serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv->serv_addr.sin_port = htons(portno);
  if (bind(serv->sockfd, (struct sockaddr *) &serv->serv_addr,
	   sizeof(serv->serv_addr)) < 0)
    my_error("ERROR on binding", 1, 0);
  listen(serv->sockfd, MCO);
  return (0);
}

int			main_loop(t_servd *servd, pthread_t *thread, t_serv *serv)
{
  int			i;

  i = 0;
  while (i < MCO && (51 + (50 * i)) < 1002)
    {
      printf("Waiting for a client...\n");
      servd[i].clilen = sizeof(servd[i].cli_addr);
      servd[i].newsockfd = accept(serv->sockfd,
				  (struct sockaddr *) &servd[i].cli_addr,
				  &servd[i].clilen);
      if (servd[i].newsockfd < 0)
	my_error("ERROR on accept", 1, 0);
      printf("New client, number %d\n", i + 1);
      servd[i].serv = serv;
      pthread_mutex_lock(&serv->mutex);
      servd[i].y = 0 + (GRP_SIZE * serv->j);
      servd[i].ym = GRP_SIZE + 1 + (GRP_SIZE * serv->j);

      pthread_mutex_unlock(&serv->mutex);
      pthread_create(&thread[i], NULL, new_listener, &servd[i]);
      pthread_mutex_lock(&serv->mutex);
      serv->j = serv->j + 1;
      i = serv->j;
      pthread_mutex_unlock(&serv->mutex);
    }
  return (0);
}
