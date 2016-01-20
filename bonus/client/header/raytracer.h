/*
** raytracer.h for raytracer in /home/archer_j/rendu/raytracer_tmp
** 
** Made by archer
** Login   <archer_j@epitech.net>
** 
** Started on  Tue May  6 17:13:37 2014 archer
** Last update Sun Jun  8 21:34:54 2014 lagier_e
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# include		<stdio.h>
# include		<pthread.h>

# define CEIL(Val, Max)	((Val > Max) ? (Max) : (Val))
# define WIN(V, Mi, Ma)	((V > Mi && V < Ma)) ? V : ((V >= Ma) ? Ma : Mi)
# define SQUARE(Value)	(Value * Value)

# define UNUSED		__attribute__((unused))
# define USAGE		"usage: ./rt config_file\n"
# define WIN_NAME	"Raytracer win42"

# define SPHERE		0
# define CONE		1
# define PLAN		2
# define CYLINDRE	3

# define CORE		8
# define SPOTS_LIMIT	500
# define TRAVEL_LIMIT	20
# define ESCAPE		65307
# define SHADOW_FACTOR	300

typedef struct s_object	t_object;
typedef struct s_coord	t_coord;
typedef struct s_bright	t_bright;
typedef struct s_color	t_color;
typedef struct s_class	t_class;
typedef struct s_list	t_list;
typedef struct s_spot	t_spot;
typedef struct s_glob	t_glob;
typedef struct s_file	t_file;
typedef struct s_eye	t_eye;
typedef struct s_all	t_all;

/*
** Lexer struct
*/
struct			s_list
{
  char			*lexeme;
  int			type;
  t_list		*prev;
  t_list		*next;
};

struct			s_coord
{
  double		x;
  double		y;
  double		z;
};

struct			s_bright
{
  float			r;
  float			g;
  float			b;
};

struct			s_color
{
  double		r;
  double		g;
  double		b;
};

struct			s_eye
{
  t_coord		pos;
  t_coord		rot;
  t_coord		vectn;
  t_coord		vectv;
  double		fill_light;
};

struct			s_spot
{
  t_coord		pos;
  t_color		color;
  double		orientation;
  double		intensity;
  double		radius;
  t_spot		*next;
};

struct			s_object
{
  t_coord		pos;
  t_coord		rot;
  t_coord		limits_inf;
  t_coord		limits_sup;
  t_color		color;
  double		transparency;
  double		distortion;
  double		brightness;
  double		reflexion;
  double		infos;
  int			normale;
  int			type;
  t_object		*next;
};

struct			s_class
{
  char			*name;
  t_object		object_elem;
  t_spot		spot_elem;
  t_class		*next;
};

struct			s_glob
{
  double		anti_aliasing;
  double		size_x;
  double		size_y;
  double		ambient_light;
};

/*
** Core struct
*/
typedef struct		s_pixel
{
  char			act;
  int			typ;
  double		k;
  short			r;
  short			g;
  short			b;
}			t_pixel;

typedef struct		s_windows
{
  void			*mlx_ptr;
  void			*win_ptr;
}			t_windows;

typedef struct		s_mlximg
{
  void			*img_ptr;
  char			*data;
  int			width;
  int			height;
  int			bpp;
  int			sizeline;
  int			endian;
}			t_mlximg;

/*
** Parser struct
*/
struct			s_file
{
  char			*name;
  t_file		*next;
};

struct			s_all
{
  t_windows		*win;
  t_mlximg		*img;
  t_object		*objects;
  t_class		*class;
  t_spot		*spots;
  t_glob		global;
  t_file		*files;
  t_eye			eye;
  t_eye			r_eye;
  double		x;
  double		y;
  char			*ip;
  char			*port;
  int			travels;
  int			ymin;
  int			ymax;
  int			sockfd;
};

typedef struct		s_thread_data
{
  t_all			*data;
  int			x;
  int			y;
  int			xm;
  int			tymin;
  int			tymax;
  pthread_mutex_t	*mutex;
  pthread_mutex_t	*mutex2;
}			t_thread_data;

#endif	/* !RAYTRACER_H_ */
