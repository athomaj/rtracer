/*
** core.h for core in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Mon May 26 17:15:00 2014 maillot
** Last update Sun Jun  8 23:24:33 2014 maillot
** Last update Sun Jun  8 09:22:06 2014 athomasjulien
*/

#ifndef CORE_H_
# define CORE_H_

# include	<X11/X.h>
# include	<stdlib.h>
# include	<math.h>
# include	"mlx.h"
# include	"raytracer.h"

void		*raytracer_display(void *);
int		calc_precision_intersection(t_all *, t_pixel *, int, int);

/*
** check k and pixel functions in check_functions.c file
*/
void		check_k(t_pixel *, t_all *, t_object *, t_eye *);
int		check_diff_between_tmp_and_buff(t_pixel *, t_pixel *);

/*
** main functions in core.c file
*/
int		core_start(t_all *);

/*
** mlx functions and pxl to img functions in core_mlx.c file
*/
int		key_control(int , t_all **);
int		my_control_expose(t_all *);
void		save_in_pixel(t_pixel *, t_pixel *);
void		my_pixel_put_to_img(t_all *, t_pixel *, int, int);

/*
** initialization functions in init_core_functions.c file
*/
void		init_struct_eye(t_all *, t_eye *, double, double);
void		init_struct_pixel(t_pixel *);
int		init_raytracer_win_img(t_all *);

/*
** start calculates intersection functions in init_intersection.c fime
*/
void		calculates_shape(t_pixel *, t_eye *, t_object *);

/*
** intersection caculates functions in intersection.c file
*/
double		inter_plan(t_eye *, t_object *);
double		inter_sphere(t_eye *, t_object *);
double		inter_cylinder(t_eye *, t_object *);
double		inter_cone(t_eye *, t_object *);

/*
** Shade and ligh functions in shadowlight folder
*/
void		fill_light(t_eye *, t_pixel *);
void		init_reflection(t_eye *, t_eye *, t_coord *, t_coord *);
void		reflection(t_all *, t_object *, t_pixel *, t_eye *);
void		lum_shadow(t_all *, t_coord *, t_object *, t_pixel *);
int		calc_light(t_all *, t_pixel *, t_object *);
void		init_lum_shadow(t_all *, t_object *, t_pixel *, t_eye *);
float		calc_inter(t_coord *, t_coord *, t_object *);
int		calc_obj(t_object *, t_object *, t_eye *);
void		calc_vector_n(t_object *, t_coord *, t_coord *);
double		calc_cos(t_coord *, t_coord *, t_coord *, double);

/*
** Limit functions in limit.c file
*/
double		limit_x(t_eye *, t_object *, double [2]);
double		limit_y(t_eye *, t_object *, double [2]);
double		limit_z(t_eye *, t_object *, double [2]);
double		init_limit(t_eye *, t_object *, double [5]);

/*
** Initialization of object limit in limit_init.c file
*/
void		init_limit_rayon_x(t_object *, double *, double *);
void		init_limit_rayon_y(t_object *, double *, double *);
void		init_limit_rayon_z(t_object *, double *, double *);
void		init_limit_inf_x(t_object *, double *, double *);
void		init_limit_inf_y(t_object *, double *, double *);

/*
** Call limit function in limit_next_init.c
*/
int		check_limit_x(t_eye *, t_object *, double [2], double [2]);
int		check_limit_y(t_eye *, t_object *, double [2], double [2]);
void		init_limit_inf_z(t_object *, double *, double *);

#endif /* !CORE_H_ */
