/*
** transformation.h for transformation in /home/maillo_f/rendu/raytracer_tmp/core
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 23:31:49 2014 maillot
** Last update Sun Jun  8 14:38:10 2014 borel_d
*/

#ifndef TRANSFORMATION_H_
# define TRANSFORMATION_H_

# include	"raytracer.h"

void		rotate_eye(t_eye *);
void		rotate_x(double *, double *, double *, double);
void		rotate_y(double *, double *, double *, double);
void		rotate_z(double *, double *, double *, double);
void		rotate_pos_vec(t_eye *, t_object *, int);
void		translation(t_eye *, t_object *, int);
void		translation_vect(t_coord *, t_object *, int);

#endif	/* !TRANSFORMATION_H_ */
