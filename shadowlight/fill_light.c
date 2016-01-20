/*
** fill_light.c for fill_ligh in /home/maillo_f/rendu/raytracer_tmp
** 
** Made by maillot
** Login   <maillo_f@epitech.net>
** 
** Started on  Sat Jun  7 22:33:58 2014 maillot
** Last update Sun Jun  8 07:51:13 2014 athomasjulien
*/

#include	"core.h"
#include	"raytracer.h"

void		fill_light(t_eye *eye, t_pixel *pts)
{
  if ((pts->r = pts->r * eye->fill_light) > 255 ||
      pts->r < 0)
    (pts->r > 255)? (pts->r = 255) : (pts->r = 0);
  if ((pts->g = pts->g * eye->fill_light) > 255 ||
      pts->g < 0)
    (pts->g > 255)? (pts->g = 255) : (pts->g = 0);
  if ((pts->b = pts->b * eye->fill_light) > 255 ||
      pts->b < 0)
    (pts->b > 255)? (pts->b = 255) : (pts->b = 0);
}
