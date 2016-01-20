/*
** brightness.c for brightness in /home/borel_d/Downloads/raytracer/raytracer_tmp/shadowlight
** 
** Made by borel_d
** Login   <borel_d@epitech.net>
** 
** Started on  Sun Jun  8 02:07:42 2014 borel_d
** Last update Sun Jun  8 05:02:55 2014 borel_d
*/

#include	<math.h>
#include	"core.h"
#include	"raytracer.h"

static void	end_brightness(t_pixel *pixel, t_bright *colors)
{
  pixel->r = WIN(colors->r, 0, 255);
  pixel->g = WIN(colors->g, 0, 255);
  pixel->b = WIN(colors->b, 0, 255);
}

static void	calc_brightness(t_bright *colors, t_object *obj,
				t_spot *light, double angle)
{
  double	bright;
  float		shine;

  bright = ((double) (WIN(light->intensity, 0, 100)) / 100) * angle;
  shine = (float) (WIN(obj->brightness, 0, 100)) / 100;
  if (angle > 0.000)
    {
      colors->r += (obj->color.r * (1 - shine) +
		    light->color.r * shine) * bright;
      colors->g += (obj->color.g * (1 - shine) +
		    light->color.g * shine) * bright;
      colors->b += (obj->color.b * (1 - shine) +
		    light->color.b * shine) * bright;
    }
}

static void	init_colors(t_bright *colors, t_object *obj)
{
  colors->r = obj->color.r / 20;
  colors->g = obj->color.g / 20;
  colors->b = obj->color.b / 20;
}

void		lum_shadow(t_all *all, t_coord *pt_inter,
			   t_object *object, t_pixel *pixel)
{
  t_spot	*spots_tmp;
  t_coord	v_norm;
  t_bright	colors;
  double	cos_a;
  double	vnnorm;

  spots_tmp = all->spots;
  init_colors(&colors, object);
  calc_vector_n(object, pt_inter, &v_norm);
  if (object->reflexion > 0)
    init_reflection(&all->r_eye, &all->eye, &v_norm, pt_inter);
  vnnorm = sqrt(pow(v_norm.x, 2) + pow(v_norm.y, 2) + pow(v_norm.z, 2));
  while (spots_tmp != NULL)
    {
      cos_a = calc_cos(&spots_tmp->pos, pt_inter, &v_norm, vnnorm);
      calc_brightness(&colors, object, spots_tmp, cos_a);
      spots_tmp = spots_tmp->next;
    }
  end_brightness(pixel, &colors);
}
