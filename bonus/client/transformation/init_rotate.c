/*
** rotate.c for rotate in /home/maillo_f/rendu/raytracer_tmp/transformation
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat May 31 21:25:07 2014 maillot
** Last update Sun Jun  8 16:22:35 2014 borel_d
*/

#include	"raytracer.h"
#include	"transformation.h"

void		rotate_eye(t_eye *eye)
{
  rotate_x(&eye->vectv.x, &eye->vectv.y, &eye->vectv.z, -(eye->rot.z));
  rotate_y(&eye->vectv.x, &eye->vectv.y, &eye->vectv.z, -(eye->rot.y));
  rotate_z(&eye->vectv.x, &eye->vectv.y, &eye->vectv.z, -(eye->rot.x));
}
