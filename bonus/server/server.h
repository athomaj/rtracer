/*
** carre.h for carre in /home/lagier_e/rendu/colle2
**
** Made by lagier_e
** Login   <lagier_e@epitech.net>
**
** Started on  Mon May  5 19:17:33 2014 lagier_e
** Last update Sun Jun  8 23:24:52 2014 lagier_e
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<pthread.h>

# define		MCO		20
# define		GRP_SIZE	50

typedef struct		s_windata
{
  void			*ptr;
  void			*win;
  void			*img;
  char			*data;
  int			bpp;
  int			size;
  int			endian;
}			t_windata;

typedef struct		s_thread_data
{
  char			*data;
  int			sock;
  struct s_windata	*win;
  pthread_mutex_t	*mutex;
}			t_thread_data;

typedef struct		s_serv
{
  int			sockfd;
  struct sockaddr_in	serv_addr;
  pthread_mutex_t	mutex;
  char			*file;
  struct s_windata	win;
  int			xwin;
  int			ywin;
  int			j;
}			t_serv;

typedef struct		s_servd
{
  struct s_serv		*serv;
  int			y;
  int			ym;
  int			newsockfd;
  socklen_t		clilen;
  struct sockaddr_in	cli_addr;
}			t_servd;

void			my_pixel(char *, int, int, int);
void			ini_background(char *, int, t_serv *);
void			*new_listener(void *);
int			show_img(int, t_serv *, int, t_servd *);
int			my_error(char *, int, int);
int			ini_server(char *, t_serv *);
int			ini_win(t_serv *);
int			main_loop(t_servd *, pthread_t *, t_serv *);
int			manage_key(int, void *);
int			manage_expose(void *);
int			my_nb(char *, int *);
int			my_mlx_loop(t_serv *);

#endif			/* !SERVER_H_ */
