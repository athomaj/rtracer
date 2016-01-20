/*
** core.h for core in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Mon May 26 17:15:00 2014 maillot
** Last update Sun Jun  8 21:24:40 2014 lagier_e
*/

#ifndef CORE_H_
# define CORE_H_

# include	<X11/X.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>
# include	"mlx.h"
# include	"raytracer.h"

void		*raytracer_display(void *);
int		calc_precision_intersection(t_all *, t_pixel *, int, int);
int		my_error(char *);
int		ini_connection(char *, int, t_all *);
int		my_nb(char *, int *);
int		send_end(t_all *);
int		my_call_thread(t_all *);

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
int		key_control(int, t_all **);
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
int		check_limit_x(t_eye *, t_object *, double *, double *);
int		check_limit_y(t_eye *, t_object *, double *, double *);
void		init_limit_inf_z(t_object *, double *, double *);
void		init_limit_rayon_x(t_object *, double *, double *);
void		init_limit_rayon_y(t_object *, double *, double *);
void		init_limit_rayon_z(t_object *, double *, double *);
void		init_limit_inf_x(t_object *, double *, double *);
void		init_limit_inf_y(t_object *, double *, double *);
double		init_limit(t_eye *, t_object *, double[5]);
double		limit_x(t_eye *, t_object *, double *);
double		limit_y(t_eye *, t_object *, double *);
double		limit_z(t_eye *, t_object *, double *);
double		init_limit(t_eye *, t_object *, double *);

#endif /* !CORE_H_ */
