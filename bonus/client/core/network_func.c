/*
** network_func.c for raytracer in /home/lagier_e/rendu/final2/raytracer_tmp
** 
** Made by lagier_e
** Login   <lagier_e@epitech.net>
** 
** Started on  Sun Jun  8 21:07:20 2014 lagier_e
** Last update Sun Jun  8 21:13:59 2014 lagier_e
*/

#include		<string.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<sys/socket.h>
#include		<fcntl.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		"transformation.h"
#include		"raytracer.h"
#include		"core.h"

int			my_error(char *msg)
{
  fprintf(stderr, msg);
  return (-1);
}

int			my_nb(char *buffer, int *i)
{
  int			j;
  char			nb[4006];

  j = 0;
  *i = *i + 1;
  while (buffer[j] && buffer[j] != '*')
    {
      nb[j] = buffer[j];
      j = j + 1;
      *i = *i + 1;
    }
  nb[j] = 0;
  return (atoi(nb));
}

int			ini_connection(char *ip, int port, t_all *data)
{
  struct sockaddr_in	serv_addr;
  struct hostent	*server;
  char			buffer[4006];
  int			i;

  i = 0;
  if ((data->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||
      (server = gethostbyname(ip)) == NULL)
    return (my_error("Error connecting\n"));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(ip);
  serv_addr.sin_port = htons(port);
  if (connect(data->sockfd, (const struct sockaddr *)&serv_addr,
	      sizeof(serv_addr)) < 0)
    return (my_error("Error connecting\n"));
  memset(buffer, 0, 4006);
  if (recv(data->sockfd, buffer, 4005, MSG_WAITALL) <= 0)
    return (my_error("Error reading from socket\n"));
  data->ymin = my_nb(buffer + i + 1, &i);
  data->ymax = my_nb(buffer + i + 1, &i);
  return (0);
}
